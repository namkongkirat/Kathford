/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testingMultiThreading;

/**
 *
 * @author namko
 */
public class ThreadSame extends Thread{
    public void run(){
        for(int i=0; i<5; i++){
        try{
            Thread.sleep(500);
        }
        catch(InterruptedException e){
            System.out.println(e);
        }
        System.out.println(i);
        }
    }
    
    public static void main(String args[]){
    ThreadSame t1 = new ThreadSame();
    ThreadSame t2 = new ThreadSame();
    t1.start();
    try{
        t1.join();
    }
    catch(Exception e){
    System.out.println(e);
    }
    t2.start();
    }
}
