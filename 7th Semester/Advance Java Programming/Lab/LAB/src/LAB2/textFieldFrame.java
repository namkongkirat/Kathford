/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package LAB2;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

/**
 *
 * @author namko
 */
public class textFieldFrame extends JFrame {
    JTextField textfield1, textfield2, textfield3;
    JPasswordField password1;
    public textFieldFrame(){
        super("Text and Password");
        setLayout(new FlowLayout());
        textfield1 = new JTextField("",25);
        add(textfield1);
        
        TextHandler handler1 = new TextHandler();
        textfield1.addActionListener(handler1);
                
        textfield2 = new JTextField("Kathford");
        add(textfield2);
        textfield3 = new JTextField("Kathford");
        textfield3.setEditable(false);
        add(textfield3);
        password1 = new JPasswordField("Kathford");
        add(password1);
    }

    public class TextHandler implements ActionListener{
        public ActionEvent event1, event2, event3;
            public void actionPerformed(ActionEvent e){
                    String action = e.getActionCommand();
                    String message = "You typed " + action;
                    JOptionPane.showMessageDialog(textFieldFrame.this, message);
            }            
        }
        
    }

