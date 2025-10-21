package com.caro.ui;

import com.caro.model.Player;

import javax.swing.*;
import java.awt.*;

public class DualLoginUI extends JFrame {
    private PlayerPanel player1Panel;
    private PlayerPanel player2Panel;
    private JButton startGameButton;

    public DualLoginUI() {
        super("Game Caro - Đăng nhập 2 người chơi");

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(900, 800);
        setLocationRelativeTo(null);
        setResizable(false);

        initUI();
    }

    private void initUI() {
        setLayout(new BorderLayout(15, 15));

        // Title panel
        JPanel titlePanel = new JPanel();
        titlePanel.setBackground(new Color(240, 240, 240));
        JLabel titleLabel = new JLabel("GAME CARO - 2 NGƯỜI CHƠI");
        titleLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 28));
        titleLabel.setForeground(new Color(51, 51, 51));
        titlePanel.add(titleLabel);
        add(titlePanel, BorderLayout.NORTH);

        // Center panel with 2 player panels
        JPanel centerPanel = new JPanel(new GridLayout(1, 2, 20, 0));
        centerPanel.setBorder(BorderFactory.createEmptyBorder(20, 30, 20, 30));

        player1Panel = new PlayerPanel("NGƯỜI CHƠI 1", new Color(220, 53, 69));
        player2Panel = new PlayerPanel("NGƯỜI CHƠI 2", new Color(0, 123, 255));

        // Set callbacks
        player1Panel.setOnLoginCallback(this::checkBothLoggedIn);
        player2Panel.setOnLoginCallback(this::checkBothLoggedIn);

        centerPanel.add(player1Panel);
        centerPanel.add(player2Panel);

        add(centerPanel, BorderLayout.CENTER);

        // Bottom panel with start button
        JPanel bottomPanel = new JPanel();
        bottomPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 20, 10));

        startGameButton = new JButton("BẮT ĐẦU CHƠI");
        startGameButton.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 18));
        startGameButton.setPreferredSize(new Dimension(200, 50));
        startGameButton.setBackground(new Color(40, 167, 69));
        startGameButton.setForeground(Color.WHITE);
        startGameButton.setFocusPainted(false);
        startGameButton.setEnabled(false);
        startGameButton.addActionListener(e -> startGame());

        bottomPanel.add(startGameButton);
        add(bottomPanel, BorderLayout.SOUTH);
    }

    private void checkBothLoggedIn() {
        if (player1Panel.isLoggedIn() && player2Panel.isLoggedIn()) {
            startGameButton.setEnabled(true);
            JOptionPane.showMessageDialog(this,
                    "Cả hai người chơi đã sẵn sàng!\nClick 'BẮT ĐẦU CHƠI' để tiếp tục.",
                    "Sẵn sàng", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    private void startGame() {
        Player player1 = player1Panel.getLoggedInPlayer();
        Player player2 = player2Panel.getLoggedInPlayer();

        if (player1 == null || player2 == null) {
            JOptionPane.showMessageDialog(this,
                    "Vui lòng đảm bảo cả hai người chơi đã đăng nhập!",
                    "Lỗi", JOptionPane.ERROR_MESSAGE);
            return;
        }

        // Kiểm tra ký tự trùng
        if (player1.getSymbol().equals(player2.getSymbol())) {
            JOptionPane.showMessageDialog(this,
                    "Hai người chơi không được chọn cùng ký tự!\nVui lòng đổi ký tự.",
                    "Lỗi", JOptionPane.ERROR_MESSAGE);
            return;
        }

        // Chọn kích thước bàn cờ
        int boardSize = askBoardSize();

        // Mở GameUI
        dispose();
        SwingUtilities.invokeLater(() -> {
            GameUI gameUI = new GameUI(player1, player2, boardSize);
            gameUI.setVisible(true);
        });
    }

    private int askBoardSize() {
        String[] options = {"5x5", "10x10", "15x15", "20x20", "Tùy chỉnh"};
        int choice = JOptionPane.showOptionDialog(
                this,
                "Chọn kích thước bàn cờ:",
                "Thiết lập Game Caro",
                JOptionPane.DEFAULT_OPTION,
                JOptionPane.QUESTION_MESSAGE,
                null,
                options,
                options[2]
        );

        switch (choice) {
            case 0: return 5;
            case 1: return 10;
            case 2: return 15;
            case 3: return 20;
            case 4:
                String input = JOptionPane.showInputDialog(
                        this,
                        "Nhập kích thước bàn cờ (5-30):",
                        "Tùy chỉnh kích thước",
                        JOptionPane.QUESTION_MESSAGE
                );

                if (input != null) {
                    try {
                        int customSize = Integer.parseInt(input.trim());
                        if (customSize >= 5 && customSize <= 30) {
                            return customSize;
                        } else {
                            JOptionPane.showMessageDialog(
                                    this,
                                    "Kích thước phải từ 5 đến 30. Sử dụng mặc định 15.",
                                    "Thông báo",
                                    JOptionPane.WARNING_MESSAGE
                            );
                        }
                    } catch (NumberFormatException e) {
                        JOptionPane.showMessageDialog(
                                this,
                                "Giá trị không hợp lệ. Sử dụng mặc định 15.",
                                "Lỗi",
                                JOptionPane.ERROR_MESSAGE
                        );
                    }
                }
                return 15;
            default:
                return 15;
        }
    }
}