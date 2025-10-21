package com.caro.database;

import com.caro.model.Player;

import java.sql.*;

public class PlayerDAO {

    // Đăng ký người chơi mới
    public static boolean registerPlayer(String username, String displayName, String password) {
        String sql = "INSERT INTO players (username, display_name, password) VALUES (?, ?, ?)";

        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, username);
            pstmt.setString(2, displayName);
            pstmt.setString(3, password);  // Trong thực tế nên hash password

            int rowsAffected = pstmt.executeUpdate();
            return rowsAffected > 0;

        } catch (SQLException e) {
            if (e.getSQLState().equals("23505")) {  // Unique violation
                System.err.println("Username already exists!");
            } else {
                e.printStackTrace();
            }
            return false;
        }
    }

    // Đăng nhập
    public static Player loginPlayer(String username, String password) {
        String sql = "SELECT * FROM players WHERE username = ? AND password = ?";

        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, username);
            pstmt.setString(2, password);

            ResultSet rs = pstmt.executeQuery();

            if (rs.next()) {
                Player player = new Player(
                        rs.getString("username"),
                        rs.getString("password"),
                        rs.getString("display_name")
                );
                player.setGamesPlayed(rs.getInt("games_played"));
                player.setGamesWon(rs.getInt("games_won"));
                player.setWinRate(rs.getDouble("win_rate"));
                return player;
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }

        return null;  // Login failed
    }

    // Kiểm tra username đã tồn tại chưa
    public static boolean isUsernameExists(String username) {
        String sql = "SELECT COUNT(*) FROM players WHERE username = ?";

        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, username);
            ResultSet rs = pstmt.executeQuery();

            if (rs.next()) {
                return rs.getInt(1) > 0;
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }

        return false;
    }

    // Cập nhật thống kê sau khi chơi
    public static boolean updatePlayerStats(String username, boolean won) {
        String sql = "UPDATE players SET " +
                "games_played = games_played + 1, " +
                "games_won = games_won + ?, " +
                "win_rate = ROUND((games_won + ?::DECIMAL) / (games_played + 1) * 100, 2), " +
                "updated_at = CURRENT_TIMESTAMP " +
                "WHERE username = ?";

        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            int wonValue = won ? 1 : 0;
            pstmt.setInt(1, wonValue);
            pstmt.setInt(2, wonValue);
            pstmt.setString(3, username);

            int rowsAffected = pstmt.executeUpdate();
            return rowsAffected > 0;

        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }

    // Lấy thông tin người chơi
    public static Player getPlayer(String username) {
        String sql = "SELECT * FROM players WHERE username = ?";

        try (Connection conn = DatabaseConnection.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, username);
            ResultSet rs = pstmt.executeQuery();

            if (rs.next()) {
                Player player = new Player(
                        rs.getString("username"),
                        rs.getString("password"),
                        rs.getString("display_name")
                );
                player.setGamesPlayed(rs.getInt("games_played"));
                player.setGamesWon(rs.getInt("games_won"));
                player.setWinRate(rs.getDouble("win_rate"));
                return player;
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }

        return null;
    }
}