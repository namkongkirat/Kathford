/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jOptionPane;

/**
 *
 * @author namko
 */
import javax.swing.JOptionPane;

public class JOpPane {
    public static void main (String args[]){
    String first = JOptionPane.showInputDialog("First Num");
    String second = JOptionPane.showInputDialog("Second Num");
    int f = Integer.parseInt(first);
    int s = Integer.parseInt(second);
    int sum = f+s;
    JOptionPane.showMessageDialog(null,"The sum is: "+ sum,"Sum of 2 Int" ,JOptionPane.PLAIN_MESSAGE);
    }
}
