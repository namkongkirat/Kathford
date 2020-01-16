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
public class ExceptionTest {
    static void test(int a) throws CustomException{
    if(a>10){
        throw new CustomException(a);
    }
    System.out.println("No Exception.");
    }
    public static void main(String args[]){
        try{
        test(5);
        test(20);
        }
        catch(CustomException e){
            System.out.println(e);
        }
    }
    
}
