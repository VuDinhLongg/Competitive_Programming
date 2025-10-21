package com.caro.model;

public class Game {
    private final int size;
    private final int[][] board;  // 0=empty, 1=X, 2=O
    private int currentPlayer;    // 1=X, 2=O
    private boolean gameOver;
    private int moveCount;

    public Game(int size) {
        if (size < 5) {
            throw new IllegalArgumentException("Kích thước bàn cờ phải >= 5");
        }
        this.size = size;
        this.board = new int[size][size];
        this.currentPlayer = 1;
        this.gameOver = false;
        this.moveCount = 0;
    }

    public int getSize() {
        return size;
    }

    public int getCurrentPlayer() {
        return currentPlayer;
    }

    public boolean isGameOver() {
        return gameOver;
    }

    public int[][] getBoard() {
        return board;
    }

    public boolean isDraw() {
        return moveCount == size * size && gameOver;
    }

    public boolean makeMove(int row, int col) {
        if (gameOver || row < 0 || row >= size || col < 0 || col >= size || board[row][col] != 0) {
            return false;
        }

        board[row][col] = currentPlayer;
        moveCount++;

        if (checkWin(row, col)) {
            gameOver = true;
            return true;
        }

        if (moveCount == size * size) {
            gameOver = true;
            return true;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        return true;
    }

    public boolean checkWin(int row, int col) {
        int player = board[row][col];

        // Check horizontal
        int count = 0;
        for (int c = 0; c < size; c++) {
            count = (board[row][c] == player) ? count + 1 : 0;
            if (count == 5) return true;
        }

        // Check vertical
        count = 0;
        for (int r = 0; r < size; r++) {
            count = (board[r][col] == player) ? count + 1 : 0;
            if (count == 5) return true;
        }

        // Check diagonal
        count = 0;
        for (int i = -4; i <= 4; i++) {
            int r = row + i;
            int c = col + i;
            if (r >= 0 && r < size && c >= 0 && c < size) {
                count = (board[r][c] == player) ? count + 1 : 0;
                if (count == 5) return true;
            }
        }

        // Check anti-diagonal
        count = 0;
        for (int i = -4; i <= 4; i++) {
            int r = row + i;
            int c = col - i;
            if (r >= 0 && r < size && c >= 0 && c < size) {
                count = (board[r][c] == player) ? count + 1 : 0;
                if (count == 5) return true;
            }
        }

        return false;
    }

    public void resetGame() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                board[i][j] = 0;
            }
        }
        currentPlayer = 1;
        gameOver = false;
        moveCount = 0;
    }
}