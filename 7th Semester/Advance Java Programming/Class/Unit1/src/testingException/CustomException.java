/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingException;

/**
 *
 * @author namko
 */
public class CustomException extends Exception{
    int a;
    public CustomException(int b){
    a=b;
    }
    public String toString(){
    return "Exception:["+a+"]";
    }
}
