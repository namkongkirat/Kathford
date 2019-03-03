/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingInterface;

/**
 *
 * @author namko
 */
public class Client implements Callback{
    public void Callback (int p) {
        System.out.println("Callback called with "+p);
    }    
    void nonInterfaceMethod(){
        System.out.println("Classes that implements interfaces" + "may also define other members too.");
    }
}
