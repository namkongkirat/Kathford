/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingButton;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

/**
 *
 * @author namko
 */
public class ButtonFrame extends JFrame {

    private JButton butt1;
    private JButton butt2;

    public ButtonFrame()
    {
        super("Testing JButton");
        setLayout(new FlowLayout());
        Icon img=new ImageIcon(getClass().getResource("image1.jpg"));

        butt2=new JButton("Plain Button");
        add(butt2);

        butt1=new JButton("Fancy Button");
        butt1.setIcon(img);
        add(butt1);

        ButtonHandler handler=new ButtonHandler();
        butt1.addActionListener(handler);
        butt2.addActionListener(handler);
    }
    private class ButtonHandler implements ActionListener
    {
        public void actionPerformed(ActionEvent event)
        {
            JOptionPane.showMessageDialog(ButtonFrame.this,String.format("You clicked %s",event.getActionCommand()));
        }
    }

}