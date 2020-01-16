/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package LayoutManagers;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
/**
 *
 * @author namko
 */
public class gridLayout extends JFrame implements ActionListener{
    GridLayout layout1;
    GridLayout layout2;
    JButton[] buttons;
    Container container;
    Boolean toggle = true;
    static final String[] names ={"1","2","3","4","5","6"};
    
    public gridLayout(){
        layout1 = new GridLayout(2,3);
        layout2 = new GridLayout(3,2);
        setLayout(layout1);
        container=getContentPane();
        buttons = new JButton[names.length];
        
        for(int i=0; i<names.length;i++){
            buttons[i] = new JButton(names[i]);
            buttons[i].addActionListener(this);
            add(buttons[i]);
        }
        
    }
    
    public void actionPerformed(ActionEvent e){
        if(toggle==true)
            container.setLayout(layout2);
        else
            container.setLayout(layout1);
        toggle=!toggle;
        container.validate();
    }
    
    public static void main(String args[]){
     gridLayout a = new gridLayout();
     a.setSize(500,500);
     a.setVisible(true);
    }
}
