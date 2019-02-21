/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingFunctionOverloading;

/**
 *
 * @author namko
 */
public class OverloadFuns {
    public static void main(String args[]){
    Box mybox1 = new Box();
    Box mybox2 = new Box();
    Box mybox3 = new Box();
    //double vol;
    System.out.println("Volume of box1 is " + mybox1.setDim(10,20,15));
    System.out.println("Volume of box2 is " + mybox2.setDim());
    System.out.println("Volume of box3 is " + mybox3.setDim(7));
   } 
    
}
