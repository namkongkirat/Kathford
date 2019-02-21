/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingConstructorOverloading;

/**
 *
 * @author namko
 */
public class OverloadCons {
   public static void main(String args[]){
    Box mybox1 = new Box(10,20,15);
    Box mybox2 = new Box();
    Box mybox3 = new Box(7);
    //double vol;
    System.out.println("Volume of box1 is " + mybox1.volume());
    System.out.println("Volume of box2 is " + mybox2.volume());
    System.out.println("Volume of box3 is " + mybox3.volume());
   } 
}
