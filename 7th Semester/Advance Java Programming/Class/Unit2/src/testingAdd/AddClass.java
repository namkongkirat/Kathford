/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingAdd;


import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;

/**
 *
 * @author namko
 */
public class AddClass extends JFrame{
    public FlowLayout FL;
    public Container ctn;
    public JTextField tf1;
    public JTextField tf2;
    public JTextField tf3;
    public JTextField tf4;
    public JButton b1;
    
    
    public AddClass(){
        FL = new FlowLayout();
        ctn = getContentPane();
        setLayout(FL);
        tf1 = new JTextField(25);
        add(tf1);
        tf2 = new JTextField(25);
        add(tf2);
        tf4 = new JTextField(25);
        add(tf4);
        b1 = new JButton("Simple Interest");
        add(b1);
        tf3 = new JTextField("Result",25);
        tf3.setEditable(false);
        add(tf3);
                          setSize(300,300); 
                          setVisible(true); 
        b1.addActionListener(new ActionListener(){
               public void actionPerformed(ActionEvent e) { 
                    int p = Integer.parseInt(tf1.getText());
                    int t = Integer.parseInt(tf2.getText()); 
                    int r = Integer.parseInt(tf4.getText());
                    int s = (p*t*r)/100; 
                    tf3.setText("Their interest is = " + String.valueOf(s)); 
                                      }
                }); 
            } 
    
    public static void main(String[] args){
        new AddClass();
    }
   }
