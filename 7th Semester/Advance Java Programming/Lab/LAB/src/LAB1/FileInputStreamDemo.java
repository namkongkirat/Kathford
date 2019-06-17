/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package LAB1;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 *
 * @author namko
 */
public class FileInputStreamDemo {

    public static void main(String[] args )throws Exception {
        int Size;
        InputStream f = new FileInputStream ("C:\\Academics\\Codes\\Kathford\\7th Semester\\Advance Java Programming\\Lab\\LAB\\src\\LAB1\\FileInputStreamDemo.Java");
        System.out.println("Total Available Bytes:"+(Size=f.available()));
        int n=Size;
        for(int i=0; i<n; i++)
            System.out.print((char)f.read());
        
    }
    
}
