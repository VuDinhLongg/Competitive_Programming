package com.caro.ui;

import com.caro.model.Game;
import com.caro.model.Player;
import com.caro.database.PlayerDAO;
import com.caro.util.AlertUtil;

import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;

public class GameUI extends JFrame {
    private Game game;
    private Player player1;
    private Player player2;
    private JButton[][] buttons;
    private JLabel statusLabel;
    private JLabel player1Label;
    private JLabel player2Label;
    private JPanel boardPanel;

    public GameUI(Player player1, Player player2, int boardSize) {
        super("Game Caro");
        this.player1 = player1;
        this.player2 = player2;
        this.game = new Game(boardSize);
        this.buttons = new JButton[boardSize][boardSize];
        this.statusLabel = new JLabel("Lượt: " + player1.getNickname() + " (" + player1.getSymbol() + ")");
        this.player1Label = new JLabel(player1.getNickname() + " (" + player1.getSymbol() + ")");
        this.player2Label = new JLabel(player2.getNickname() + " (" + player2.getSymbol() + ")");

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        int windowSize = Math.min(900, 50 * boardSize + 100);
        setSize(windowSize, windowSize + 200);
        setLocationRelativeTo(null);

        initUI();
    }

    private void initUI() {
        setLayout(new BorderLayout());

        // Top panel với thông tin 2 người chơi
        JPanel topPanel = new JPanel(new GridLayout(3, 1));

        // Player info panel
        JPanel playerInfoPanel = new JPanel(new GridLayout(1, 2, 20, 0));
        playerInfoPanel.setBorder(BorderFactory.createEmptyBorder(10, 20, 5, 20));

        // Player 1
        JPanel p1Panel = new JPanel();
        p1Panel.setBackground(new Color(255, 240, 240));
        player1Label.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 16));
        player1Label.setForeground(player1.getColor());
        p1Panel.add(player1Label);

        // Player 2
        JPanel p2Panel = new JPanel();
        p2Panel.setBackground(new Color(240, 245, 255));
        player2Label.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 16));
        player2Label.setForeground(player2.getColor());
        p2Panel.add(player2Label);

        playerInfoPanel.add(p1Panel);
        playerInfoPanel.add(p2Panel);
        topPanel.add(playerInfoPanel);

        // VS label
        JLabel vsLabel = new JLabel("⚔ VS ⚔", SwingConstants.CENTER);
        vsLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 18));
        vsLabel.setForeground(Color.DARK_GRAY);
        topPanel.add(vsLabel);

        // Status
        statusLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 20));
        statusLabel.setHorizontalAlignment(JLabel.CENTER);
        statusLabel.setForeground(player1.getColor());
        topPanel.add(statusLabel);

        add(topPanel, BorderLayout.NORTH);

        // Game board
        boardPanel = new JPanel(new GridLayout(game.getSize(), game.getSize(), 2, 2));
        boardPanel.setBackground(new Color(204, 204, 204)); // Màu viền giữa các ô
        initBoard();

        if (game.getSize() > 20) {
            JScrollPane scrollPane = new JScrollPane(boardPanel);
            scrollPane.setPreferredSize(new Dimension(800, 800));
            add(scrollPane, BorderLayout.CENTER);
        } else {
            add(boardPanel, BorderLayout.CENTER);
        }

        // Control panel
        JPanel bottomPanel = new JPanel();

        JButton newGameButton = new JButton("Chơi lại");
        newGameButton.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 14));
        newGameButton.addActionListener(e -> resetGame());

        JButton newMatchButton = new JButton("Trận mới");
        newMatchButton.setFont(new Font(Font.SANS_SERIF, Font.PLAIN, 14));
        newMatchButton.addActionListener(e -> newMatch());

        JButton exitButton = new JButton("Thoát");
        exitButton.setFont(new Font(Font.SANS_SERIF, Font.PLAIN, 14));
        exitButton.addActionListener(e -> exit());

        bottomPanel.add(newGameButton);
        bottomPanel.add(newMatchButton);
        bottomPanel.add(exitButton);
        add(bottomPanel, BorderLayout.SOUTH);
    }

    private void initBoard() {
        boardPanel.removeAll();
        int fontSize = Math.max(16, 40 - game.getSize());

        for (int row = 0; row < game.getSize(); row++) {
            for (int col = 0; col < game.getSize(); col++) {
                JButton button = new JButton("");
                button.setFont(new Font(Font.SANS_SERIF, Font.BOLD, fontSize));
                button.setFocusPainted(false);
                button.setContentAreaFilled(true);
                button.setOpaque(true);

                // Styling cho ô trống
                button.setBackground(new Color(248, 248, 248)); // Nền xám rất nhạt
                button.setBorder(new LineBorder(new Color(204, 204, 204), 1)); // Viền xám nhạt
                button.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR)); // Cursor tay khi hover

                final int r = row;
                final int c = col;
                button.addActionListener(e -> handleMove(r, c));
                buttons[row][col] = button;
                boardPanel.add(button);
            }
        }
        boardPanel.revalidate();
        boardPanel.repaint();
    }

    private void handleMove(int row, int col) {
        // Kiểm tra xem ô đã được đánh chưa
        if (!buttons[row][col].getText().isEmpty()) {
            return; // Ô đã có người đánh rồi, không làm gì cả
        }

        // Lưu lại người chơi hiện tại TRƯỚC KHI makeMove
        int currentPlayerBeforeMove = game.getCurrentPlayer();
        Player playerWhoMoved = (currentPlayerBeforeMove == 1) ? player1 : player2;

        if (game.makeMove(row, col)) {
            JButton button = buttons[row][col];

            // Hiển thị ký tự và màu của người vừa đánh
            button.setText(playerWhoMoved.getSymbol());
            button.setForeground(playerWhoMoved.getColor());

            // Thêm hiệu ứng khi đã đánh
            button.setBackground(new Color(255, 255, 255)); // Nền trắng cho ô đã đánh
            button.setBorder(new LineBorder(playerWhoMoved.getColor(), 2)); // Viền màu của người chơi
            button.setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR)); // Đổi cursor về mặc định

            if (game.isGameOver()) {
                if (game.isDraw()) {
                    // Cả 2 đều tăng games_played
                    PlayerDAO.updatePlayerStats(player1.getUsername(), false);
                    PlayerDAO.updatePlayerStats(player2.getUsername(), false);

                    AlertUtil.showMessage(this, "Hòa! Không có người thắng.");
                } else {
                    // Người vừa đánh là người thắng
                    PlayerDAO.updatePlayerStats(playerWhoMoved.getUsername(), true);

                    // Người thua
                    Player loser = (playerWhoMoved == player1) ? player2 : player1;
                    PlayerDAO.updatePlayerStats(loser.getUsername(), false);

                    AlertUtil.showMessage(this,
                            "🎉 " + playerWhoMoved.getNickname() + " (" + playerWhoMoved.getSymbol() + ") thắng! 🎉");
                }
            } else {
                // Update status cho người chơi tiếp theo
                Player nextPlayer = (game.getCurrentPlayer() == 1) ? player1 : player2;
                statusLabel.setText("Lượt: " + nextPlayer.getNickname() + " (" + nextPlayer.getSymbol() + ")");
                statusLabel.setForeground(nextPlayer.getColor());
            }
        }
    }

    private void resetGame() {
        game.resetGame();
        for (int i = 0; i < game.getSize(); i++) {
            for (int j = 0; j < game.getSize(); j++) {
                JButton button = buttons[i][j];
                button.setText("");

                // Reset về style ban đầu
                button.setBackground(new Color(248, 248, 248));
                button.setBorder(new LineBorder(new Color(204, 204, 204), 1));
                button.setForeground(Color.BLACK);
                button.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
            }
        }
        statusLabel.setText("Lượt: " + player1.getNickname() + " (" + player1.getSymbol() + ")");
        statusLabel.setForeground(player1.getColor());
    }

    private void newMatch() {
        int confirmed = JOptionPane.showConfirmDialog(
                this,
                "Bạn có muốn bắt đầu trận đấu mới?\n(Quay về màn hình đăng nhập)",
                "Xác nhận",
                JOptionPane.YES_NO_OPTION
        );

        if (confirmed == JOptionPane.YES_OPTION) {
            dispose();
            SwingUtilities.invokeLater(() -> {
                DualLoginUI loginUI = new DualLoginUI();
                loginUI.setVisible(true);
            });
        }
    }

    private void exit() {
        int confirmed = JOptionPane.showConfirmDialog(
                this,
                "Bạn có chắc muốn thoát?",
                "Xác nhận",
                JOptionPane.YES_NO_OPTION
        );

        if (confirmed == JOptionPane.YES_OPTION) {
            System.exit(0);
        }
    }
}