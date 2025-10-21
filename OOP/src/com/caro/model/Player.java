package com.caro.model;

import java.awt.Color;

public class Player {
    private String username;
    private String password;
    private String nickname;      // Display name khi chơi
    private String symbol;        // Ký tự đại diện
    private Color color;          // Màu sắc

    // Thống kê
    private int gamesPlayed;
    private int gamesWon;
    private double winRate;

    public Player(String username, String password, String nickname) {
        this.username = username;
        this.password = password;
        this.nickname = nickname;
        this.symbol = "X";
        this.color = Color.BLACK;
        this.gamesPlayed = 0;
        this.gamesWon = 0;
        this.winRate = 0.0;
    }

    public Player(String username, String password, String nickname, String symbol, Color color) {
        this.username = username;
        this.password = password;
        this.nickname = nickname;
        this.symbol = symbol;
        this.color = color;
        this.gamesPlayed = 0;
        this.gamesWon = 0;
        this.winRate = 0.0;
    }

    // Getters and Setters
    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getNickname() {
        return nickname;
    }

    public void setNickname(String nickname) {
        this.nickname = nickname;
    }

    public String getSymbol() {
        return symbol;
    }

    public void setSymbol(String symbol) {
        this.symbol = symbol;
    }

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public int getGamesPlayed() {
        return gamesPlayed;
    }

    public void setGamesPlayed(int gamesPlayed) {
        this.gamesPlayed = gamesPlayed;
    }

    public int getGamesWon() {
        return gamesWon;
    }

    public void setGamesWon(int gamesWon) {
        this.gamesWon = gamesWon;
    }

    public double getWinRate() {
        return winRate;
    }

    public void setWinRate(double winRate) {
        this.winRate = winRate;
    }

    public String getStats() {
        return String.format("Đã chơi: %d | Thắng: %d | Tỷ lệ: %.2f%%",
                gamesPlayed, gamesWon, winRate);
    }
}