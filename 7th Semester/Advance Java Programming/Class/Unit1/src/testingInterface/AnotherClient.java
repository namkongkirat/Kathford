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
public class AnotherClient implements Callback{
    public void Callback (int q) {
        System.out.println("Another version of callback.");
        System.out.println("Callback called with "+q);
    }  
}
