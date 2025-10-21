package com.caro.util;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class AlertUtil {
    public static void showMessage(JFrame parent, String message) {
        JOptionPane.showMessageDialog(parent, message, "Thông báo", JOptionPane.INFORMATION_MESSAGE);
    }

    public static boolean confirm(JFrame parent, String message) {
        return JOptionPane.showConfirmDialog(parent, message, "Xác nhận",
                JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION;
    }
}