package LAB1;


import java.io.FileOutputStream;
import java.io.OutputStream;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author namko
 */
public class FileOutputStreamDemo {
    public static void main (String args[]) throws Exception
    {
        String Source= "This is our first lab in Java.";
        byte buf[] = Source.getBytes();
        OutputStream fo = new FileOutputStream("C:\\Users\\namko\\Desktop\\file1.txt");
        for(int i=0; i<buf.length; i++){
            fo.write(buf[i]);
        }
        fo.close();
    }
    
}
