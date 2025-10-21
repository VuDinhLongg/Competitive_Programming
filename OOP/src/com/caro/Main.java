package com.caro;

import com.caro.ui.DualLoginUI;
import javax.swing.SwingUtilities;

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            DualLoginUI dualLoginUI = new DualLoginUI();
            dualLoginUI.setVisible(true);
        });
    }
}