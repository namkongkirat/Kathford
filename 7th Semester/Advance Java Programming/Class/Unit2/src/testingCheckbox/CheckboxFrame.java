/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingCheckbox;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 *
 * @author namko
 */
public class CheckboxFrame extends JFrame {

    JTextField tf1;
    JCheckBox cb1;
    JCheckBox cb2;
    public CheckboxFrame()
    {
        setLayout(new FlowLayout());
        tf1 = new JTextField("This is the text that changes.",40);
        tf1.setFont(new Font("Serif",Font.PLAIN,14));
        add(tf1);
        cb1 = new JCheckBox("Bold");
        cb2 = new JCheckBox("Italic");
        add(cb1);
        add(cb2);
        setSize(300,300);
        setVisible(true);
        CheckBoxHandler handler = new CheckBoxHandler();
        cb1.addItemListener(handler);
        cb2.addItemListener(handler);
        
    }
    
    private class CheckBoxHandler implements ItemListener{
        public void itemStateChanged(ItemEvent e){
            if(cb1.isSelected()&&cb2.isSelected())
            tf1.setFont(new Font("Serif",Font.BOLD+Font.ITALIC,14));
            else if(cb1.isSelected())
            tf1.setFont(new Font("Serif",Font.BOLD,14));
            else if(cb2.isSelected())
            tf1.setFont(new Font("Serif",Font.ITALIC,14));
        }
    }
    
    public static void main(String args[]){
        new CheckboxFrame();
    }
}
