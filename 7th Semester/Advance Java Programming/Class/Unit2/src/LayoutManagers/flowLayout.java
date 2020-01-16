/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package LayoutManagers;


import java.awt.event.*;
import java.awt.*;
import javax.swing.*;
/**
 *
 * @author namko
 */
public class flowLayout extends JFrame{
    JButton b1,b2,b3;
    FlowLayout layout;
    Container container;
    public flowLayout(){
        layout = new FlowLayout();
        container = getContentPane();
        setLayout(layout);
        b1 = new JButton("Left");
        b2 = new JButton("Center");
        b3 = new JButton("Right");
        add(b1);
        add(b2);
        add(b3);
        setSize(500,500);
        setVisible(true);
        b1.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
            layout.setAlignment(FlowLayout.LEFT);
            layout.layoutContainer(container);
        }
        }
        );
        b2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
            layout.setAlignment(FlowLayout.CENTER);
            layout.layoutContainer(container);
        }
        });
        b3.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
            layout.setAlignment(FlowLayout.RIGHT);
            layout.layoutContainer(container);
        }
        });
        
    }
    
    public static void main(String args[]){
        new flowLayout();
    }
    
    
}
