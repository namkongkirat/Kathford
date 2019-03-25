/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingMouseEventHandling;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author namko
 */
public class MouseTrackerFrame extends JFrame{
    public JPanel mousePanel;
    public JLabel statusBar;
    public MouseTrackerFrame(){
        super("Mouse Events");
        
        mousePanel = new JPanel();
        mousePanel.setBackground(Color.red);
        add(mousePanel, BorderLayout.CENTER);
        
        statusBar = new JLabel();
        add(statusBar, BorderLayout.SOUTH);
        
        MouseHandler handler = new MouseHandler();
        mousePanel.addMouseListener(handler);
    }    
    private class MouseHandler implements MouseListener{
            
            public void mouseClicked(MouseEvent event){
                statusBar.setText(String.format("Clicked at [%d,%d]", event.getX(), event.getY()));
            }
            
            public void mouseEntered(){}
            public void mouseExited(){}
            public void mousePressed(){}
            public void mouseReleased(){}
            
        }
    }
    
}
