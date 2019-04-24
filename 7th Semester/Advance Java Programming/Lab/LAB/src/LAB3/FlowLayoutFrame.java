/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package LAB3;

import java.awt.*;  
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;  
/**
 *
 * @author namko
 */
public class FlowLayoutFrame extends JFrame{
    JButton b1, b2, b3;
    FlowLayout layout;
    Container c;
    public FlowLayoutFrame(){
        super("Flow Layout");
        layout = new FlowLayout();
        c = getContentPane();
        setLayout(layout);
        b1 = new JButton("Left");
        b2 = new JButton("Center");
        b3 = new JButton("Right");
        add(b1); add(b2); add(b3);
        
        b1.addActionListener(
                new ActionListener(){
                    public void actionPerformed(ActionEvent event){
                        layout.setAlignment(FlowLayout.LEFT);
                        layout.layoutContainer(c);
                    }
                }
        );
        b2.addActionListener(
                new ActionListener(){
                    public void actionPerformed(ActionEvent event){
                        layout.setAlignment(FlowLayout.CENTER);
                        layout.layoutContainer(c);
                    }
                }
        );
        b3.addActionListener(
                new ActionListener(){
                    public void actionPerformed(ActionEvent event){
                        layout.setAlignment(FlowLayout.RIGHT);
                        layout.layoutContainer(c);
                    }
                }
        );
    }
}
