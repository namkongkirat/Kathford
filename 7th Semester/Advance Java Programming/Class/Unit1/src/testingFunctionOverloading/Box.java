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
public class Box {
    double width;
    double height;
    double depth;
    
    double setDim(double w, double h, double d){
        width=w;
        height=h;
        depth=d;
        return width*height*depth;
    }
    double setDim(){
        width=-1;
        height=-1;
        depth=-1;
        return width*height*depth;
    }
    double setDim(double len){
        width=height=depth=len;
        return width*height*depth;
    }
    
}
