/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Usuario
 */

import java.util.ArrayList;

public class Throttle implements Subject {

    private ArrayList<Observer> observator;   //Link between Throttle and Engine
    
    public  Throttle () {
    
        observator = new ArrayList <Observer>(); 
    
    }
    
    
    public void stepThrottle(){
        //Push the engine
        notifier();
    }
    
    public void linkObserver(Observer a) {
    observator.add(a);
        
    };
    
    @Override
    public void notifier() {
        for (Observer a:observator){
            a.update();     
        }
    }
    
    
  
  
}
