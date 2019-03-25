/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingMouseEventHandling;

import javax.swing.JFrame;

/**
 *
 * @author namko
 */
public class MouseTracker {
    public static void main(String[] args)
    {
        MouseTrackerFrame m = new MouseTrackerFrame();
        m.setSize(300,300);
        m.setVisible(true);
        m.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
