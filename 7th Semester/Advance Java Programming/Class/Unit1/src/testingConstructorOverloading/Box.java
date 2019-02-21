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
public class Box {
    double width;
    double height;
    double depth;
    
    Box(double w, double h, double d){
        width=w;
        height=h;
        depth=d;
    }
    Box(){
        width=-1;
        height=-1;
        depth=-1;
    }
    Box(double len){
        width=height=depth=len;
    }
    double volume(){
    return width*height*depth;
    }
    
}
