/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingAdd;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
/**
 *
 * @author namko
 */
public class ass2num extends JFrame{
    public ass2num(){
    setLayout(new FlowLayout());
    JTextField t1 = new JTextField("First Number",10);
    JTextField t2 = new JTextField("Second Number",10);
    JButton b1 = new JButton("Add");
    add(t1);
    add(t2);
    add(b1);
    setSize(300,300);
    setVisible(true);
    b1.addActionListener(new ActionListener(){
    public void actionPerformed(ActionEvent e){
        int a = Integer.parseInt(t1.getText());
        int b = Integer.parseInt(t2.getText());
        int sum = a+b;
        JOptionPane.showMessageDialog(null,"Sum is : "+ sum,"Addition",JOptionPane.PLAIN_MESSAGE);
        
    }
    });
    }
    
    public static void main(String args[]){
    new ass2num();
    }
    
}
