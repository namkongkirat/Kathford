/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingURL;

import java.net.URL;
/**
 *
 * @author namko
 */
public class ParseURL {
    public static void main(String[] args)throws Exception{
        URL myURL = new URL("http://example.com:80/docs/books/tutorial/index.html?name=networking#DOWNLOADING");
        System.out.println("Protocol = " + myURL.getProtocol());
        System.out.println("Authority = " + myURL.getAuthority());
        System.out.println("Host = " + myURL.getHost());
        System.out.println("Port = " + myURL.getPort());
        System.out.println("Path = " + myURL.getPath());
        System.out.println("Query = " + myURL.getQuery());
        System.out.println("File = " + myURL.getFile());
        System.out.println("Reference = " + myURL.getRef());
        
    }
}
