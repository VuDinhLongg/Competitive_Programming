package com.caro.ui;

import com.caro.model.Player;
import com.caro.database.PlayerDAO;

import javax.swing.*;
import java.awt.*;
import java.util.HashMap;
import java.util.Map;

public class PlayerPanel extends JPanel {
    private final String playerName;
    private final Color themeColor;
    private boolean isLoginMode = true;
    private boolean isLoggedIn = false;
    private Player loggedInPlayer = null;

    // Login fields
    private JTextField loginUsernameField;
    private JPasswordField loginPasswordField;
    private JTextField symbolField;
    private JComboBox<String> colorComboBox;

    // Signup fields - CHỈ CẦN 3 TRƯỜNG
    private JTextField signupUsernameField;
    private JTextField signupDisplayNameField;  // Tên hiển thị khi chơi
    private JPasswordField signupPasswordField;
    private JPasswordField signupConfirmPasswordField;

    private JPanel cardPanel;
    private CardLayout cardLayout;
    private JButton actionButton;
    private JButton switchModeButton;
    private JLabel statusLabel;

    private Runnable onLoginCallback;

    // Color options
    private static final Map<String, Color> COLOR_MAP = new HashMap<>();
    static {
        COLOR_MAP.put("Đỏ", new Color(220, 53, 69));
        COLOR_MAP.put("Vàng", new Color(255, 193, 7));
        COLOR_MAP.put("Xanh dương", new Color(0, 123, 255));
        COLOR_MAP.put("Xanh lục", new Color(40, 167, 69));
        COLOR_MAP.put("Tím", new Color(111, 66, 193));
    }

    public PlayerPanel(String playerName, Color themeColor) {
        this.playerName = playerName;
        this.themeColor = themeColor;

        setLayout(new BorderLayout(10, 10));
        setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createLineBorder(themeColor, 3),
                BorderFactory.createEmptyBorder(15, 15, 15, 15)
        ));

        initUI();
    }

    private void initUI() {
        // Header
        JPanel headerPanel = new JPanel(new BorderLayout());
        JLabel titleLabel = new JLabel(playerName, SwingConstants.CENTER);
        titleLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 22));
        titleLabel.setForeground(themeColor);
        headerPanel.add(titleLabel, BorderLayout.NORTH);

        statusLabel = new JLabel("Chưa đăng nhập", SwingConstants.CENTER);
        statusLabel.setFont(new Font(Font.SANS_SERIF, Font.ITALIC, 14));
        statusLabel.setForeground(Color.GRAY);
        headerPanel.add(statusLabel, BorderLayout.CENTER);

        add(headerPanel, BorderLayout.NORTH);

        // Card panel for switching between login and signup
        cardLayout = new CardLayout();
        cardPanel = new JPanel(cardLayout);

        // Thêm scroll pane cho cả login và signup
        JScrollPane loginScrollPane = new JScrollPane(createLoginPanel());
        loginScrollPane.setBorder(null);
        loginScrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        loginScrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);

        JScrollPane signupScrollPane = new JScrollPane(createSignupPanel());
        signupScrollPane.setBorder(null);
        signupScrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        signupScrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);

        cardPanel.add(loginScrollPane, "LOGIN");
        cardPanel.add(signupScrollPane, "SIGNUP");

        add(cardPanel, BorderLayout.CENTER);

        // Button panel
        JPanel buttonPanel = new JPanel(new GridLayout(2, 1, 5, 5));

        actionButton = new JButton("Đăng nhập");
        actionButton.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 14));
        actionButton.setBackground(themeColor);
        actionButton.setForeground(Color.WHITE);
        actionButton.setFocusPainted(false);
        actionButton.addActionListener(e -> handleAction());

        switchModeButton = new JButton("Chuyển sang Đăng ký");
        switchModeButton.setFont(new Font(Font.SANS_SERIF, Font.PLAIN, 12));
        switchModeButton.setFocusPainted(false);
        switchModeButton.addActionListener(e -> switchMode());

        buttonPanel.add(actionButton);
        buttonPanel.add(switchModeButton);

        add(buttonPanel, BorderLayout.SOUTH);
    }

    private JPanel createLoginPanel() {
        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(8, 5, 8, 5);

        // Username
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.gridwidth = 2;
        JLabel usernameLabel = new JLabel("Tên đăng nhập:");
        usernameLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 13));
        panel.add(usernameLabel, gbc);

        gbc.gridy = 1;
        loginUsernameField = new JTextField(15);
        loginUsernameField.setFont(new Font(Font.SANS_SERIF, Font.PLAIN, 13));
        panel.add(loginUsernameField, gbc);

        // Password
        gbc.gridy = 2;
        JLabel passwordLabel = new JLabel("Mật khẩu:");
        passwordLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 13));
        panel.add(passwordLabel, gbc);

        gbc.gridy = 3;
        loginPasswordField = new JPasswordField(15);
        loginPasswordField.setFont(new Font(Font.SANS_SERIF, Font.PLAIN, 13));
        panel.add(loginPasswordField, gbc);

        // Symbol
        gbc.gridy = 4;
        JLabel symbolLabel = new JLabel("Ký tự của bạn (1 ký tự):");
        symbolLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 13));
        panel.add(symbolLabel, gbc);

        gbc.gridy = 5;
        symbolField = new JTextField(15);
        symbolField.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 20));
        symbolField.setHorizontalAlignment(JTextField.CENTER);
        panel.add(symbolField, gbc);

        // Color
        gbc.gridy = 6;
        JLabel colorLabel = new JLabel("Màu sắc:");
        colorLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 13));
        panel.add(colorLabel, gbc);

        gbc.gridy = 7;
        colorComboBox = new JComboBox<>(COLOR_MAP.keySet().toArray(new String[0]));
        colorComboBox.setFont(new Font(Font.SANS_SERIF, Font.PLAIN, 13));
        colorComboBox.setRenderer(new ColorComboBoxRenderer());
        panel.add(colorComboBox, gbc);

        // Enter key để login
        loginPasswordField.addActionListener(e -> handleAction());

        // Add spacing at bottom
        gbc.gridy = 8;
        gbc.weighty = 1.0;
        panel.add(Box.createVerticalGlue(), gbc);

        return panel;
    }

    private JPanel createSignupPanel() {
        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(8, 5, 8, 5);
        gbc.anchor = GridBagConstraints.WEST;

        // Username (Tên đăng nhập)
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.gridwidth = 2;
        JLabel usernameLabel = new JLabel("Tên đăng nhập:");
        usernameLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 13));
        panel.add(usernameLabel, gbc);

        gbc.gridy = 1;
        signupUsernameField = new JTextField(15);
        signupUsernameField.setFont(new Font(Font.SANS_SERIF, Font.PLAIN, 13));
        signupUsernameField.setPreferredSize(new Dimension(200, 28));
        panel.add(signupUsernameField, gbc);

        // Display Name (Tên hiển thị khi chơi)
        gbc.gridy = 2;
        JLabel displayNameLabel = new JLabel("Tên hiển thị:");
        displayNameLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 13));
        panel.add(displayNameLabel, gbc);

        gbc.gridy = 3;
        signupDisplayNameField = new JTextField(15);
        signupDisplayNameField.setFont(new Font(Font.SANS_SERIF, Font.PLAIN, 13));
        signupDisplayNameField.setPreferredSize(new Dimension(200, 28));
        panel.add(signupDisplayNameField, gbc);

        // Password
        gbc.gridy = 4;
        JLabel passwordLabel = new JLabel("Mật khẩu:");
        passwordLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 13));
        panel.add(passwordLabel, gbc);

        gbc.gridy = 5;
        signupPasswordField = new JPasswordField(15);
        signupPasswordField.setFont(new Font(Font.SANS_SERIF, Font.PLAIN, 13));
        signupPasswordField.setPreferredSize(new Dimension(200, 28));
        panel.add(signupPasswordField, gbc);

        // Hint
        gbc.gridy = 6;
        JLabel hintLabel = new JLabel("<html><i>8+ ký tự, có hoa, thường, số</i></html>");
        hintLabel.setFont(new Font(Font.SANS_SERIF, Font.PLAIN, 11));
        hintLabel.setForeground(Color.GRAY);
        panel.add(hintLabel, gbc);

        // Confirm Password
        gbc.gridy = 7;
        JLabel confirmLabel = new JLabel("Nhập lại mật khẩu:");
        confirmLabel.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 13));
        panel.add(confirmLabel, gbc);

        gbc.gridy = 8;
        signupConfirmPasswordField = new JPasswordField(15);
        signupConfirmPasswordField.setFont(new Font(Font.SANS_SERIF, Font.PLAIN, 13));
        signupConfirmPasswordField.setPreferredSize(new Dimension(200, 28));
        signupConfirmPasswordField.addActionListener(e -> handleAction());
        panel.add(signupConfirmPasswordField, gbc);

        // Add spacing at bottom to allow scrolling
        gbc.gridy = 9;
        gbc.weighty = 1.0;
        panel.add(Box.createVerticalGlue(), gbc);

        return panel;
    }

    private void switchMode() {
        isLoginMode = !isLoginMode;
        if (isLoginMode) {
            cardLayout.show(cardPanel, "LOGIN");
            actionButton.setText("Đăng nhập");
            switchModeButton.setText("Chuyển sang Đăng ký");
        } else {
            cardLayout.show(cardPanel, "SIGNUP");
            actionButton.setText("Đăng ký");
            switchModeButton.setText("Chuyển sang Đăng nhập");
        }
    }

    private void handleAction() {
        if (isLoginMode) {
            handleLogin();
        } else {
            handleSignup();
        }
    }

    private void handleLogin() {
        String username = loginUsernameField.getText().trim();
        String password = new String(loginPasswordField.getPassword());
        String symbol = symbolField.getText().trim();
        String colorName = (String) colorComboBox.getSelectedItem();

        if (username.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Vui lòng nhập tên đăng nhập!",
                    "Lỗi", JOptionPane.WARNING_MESSAGE);
            return;
        }

        if (password.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Vui lòng nhập mật khẩu!",
                    "Lỗi", JOptionPane.WARNING_MESSAGE);
            return;
        }

        if (symbol.isEmpty() || symbol.length() != 1) {
            JOptionPane.showMessageDialog(this, "Vui lòng nhập đúng 1 ký tự!",
                    "Lỗi", JOptionPane.WARNING_MESSAGE);
            return;
        }

        // Đăng nhập từ database
        Player player = PlayerDAO.loginPlayer(username, password);

        if (player == null) {
            JOptionPane.showMessageDialog(this,
                    "Sai tên đăng nhập hoặc mật khẩu!",
                    "Lỗi", JOptionPane.ERROR_MESSAGE);
            return;
        }

        Color selectedColor = COLOR_MAP.get(colorName);
        player.setSymbol(symbol);
        player.setColor(selectedColor);

        loggedInPlayer = player;
        isLoggedIn = true;

        // Update UI
        statusLabel.setText("✓ " + player.getNickname() + " (" + symbol + ")");
        statusLabel.setForeground(selectedColor);
        actionButton.setEnabled(false);
        switchModeButton.setEnabled(false);
        loginUsernameField.setEnabled(false);
        loginPasswordField.setEnabled(false);
        symbolField.setEnabled(false);
        colorComboBox.setEnabled(false);

        JOptionPane.showMessageDialog(this,
                playerName + " đã đăng nhập thành công!\n" +
                        "Chào " + player.getNickname() + "\n" +
                        "Ký tự: " + symbol + "\n\n" +
                        "=== THỐNG KÊ ===\n" +
                        player.getStats(),
                "Thành công", JOptionPane.INFORMATION_MESSAGE);

        // Trigger callback
        if (onLoginCallback != null) {
            onLoginCallback.run();
        }
    }

    private void handleSignup() {
        String username = signupUsernameField.getText().trim();
        String displayName = signupDisplayNameField.getText().trim();
        String password = new String(signupPasswordField.getPassword());
        String confirmPassword = new String(signupConfirmPasswordField.getPassword());

        if (username.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Vui lòng nhập tên đăng nhập!",
                    "Lỗi", JOptionPane.WARNING_MESSAGE);
            return;
        }

        if (displayName.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Vui lòng nhập tên hiển thị!",
                    "Lỗi", JOptionPane.WARNING_MESSAGE);
            return;
        }

        // Kiểm tra username đã tồn tại chưa
        if (PlayerDAO.isUsernameExists(username)) {
            JOptionPane.showMessageDialog(this, "Tên đăng nhập đã tồn tại!",
                    "Lỗi", JOptionPane.ERROR_MESSAGE);
            return;
        }

        if (password.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Vui lòng nhập mật khẩu!",
                    "Lỗi", JOptionPane.WARNING_MESSAGE);
            return;
        }

        String passwordError = validatePassword(password);
        if (passwordError != null) {
            JOptionPane.showMessageDialog(this, passwordError,
                    "Lỗi", JOptionPane.WARNING_MESSAGE);
            return;
        }

        if (!password.equals(confirmPassword)) {
            JOptionPane.showMessageDialog(this, "Mật khẩu nhập lại không khớp!",
                    "Lỗi", JOptionPane.WARNING_MESSAGE);
            return;
        }

        // Lưu vào database
        boolean success = PlayerDAO.registerPlayer(username, displayName, password);

        if (success) {
            JOptionPane.showMessageDialog(this,
                    "Đăng ký thành công!\n" +
                            "Tên đăng nhập: " + username + "\n" +
                            "Tên hiển thị: " + displayName + "\n\n" +
                            "Vui lòng đăng nhập và chọn ký tự & màu sắc.",
                    "Thành công", JOptionPane.INFORMATION_MESSAGE);

            // Switch to login view và điền sẵn username
            isLoginMode = true;
            cardLayout.show(cardPanel, "LOGIN");
            loginUsernameField.setText(username);
            loginPasswordField.setText(password);
            actionButton.setText("Đăng nhập");
            switchModeButton.setText("Chuyển sang Đăng ký");

            // Focus vào symbol field
            symbolField.requestFocus();
        } else {
            JOptionPane.showMessageDialog(this,
                    "Đăng ký thất bại! Vui lòng thử lại.",
                    "Lỗi", JOptionPane.ERROR_MESSAGE);
        }
    }

    private String validatePassword(String password) {
        if (password.length() < 8) {
            return "Mật khẩu phải có ít nhất 8 ký tự!";
        }

        boolean hasUpperCase = false;
        boolean hasLowerCase = false;
        boolean hasDigit = false;

        for (char c : password.toCharArray()) {
            if (Character.isUpperCase(c)) hasUpperCase = true;
            else if (Character.isLowerCase(c)) hasLowerCase = true;
            else if (Character.isDigit(c)) hasDigit = true;
        }

        if (!hasUpperCase) return "Mật khẩu phải có ít nhất một chữ cái viết hoa!";
        if (!hasLowerCase) return "Mật khẩu phải có ít nhất một chữ cái viết thường!";
        if (!hasDigit) return "Mật khẩu phải có ít nhất một chữ số!";

        return null;
    }

    public boolean isLoggedIn() {
        return isLoggedIn;
    }

    public Player getLoggedInPlayer() {
        return loggedInPlayer;
    }

    public void setOnLoginCallback(Runnable callback) {
        this.onLoginCallback = callback;
    }

    // Custom renderer for color combo box
    private class ColorComboBoxRenderer extends DefaultListCellRenderer {
        @Override
        public Component getListCellRendererComponent(JList<?> list, Object value,
                                                      int index, boolean isSelected, boolean cellHasFocus) {
            JLabel label = (JLabel) super.getListCellRendererComponent(
                    list, value, index, isSelected, cellHasFocus);

            if (value != null) {
                Color color = COLOR_MAP.get(value.toString());
                label.setForeground(color);
                label.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 13));
            }

            return label;
        }
    }
}