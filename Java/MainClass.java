/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Usuario
 */
public class MainClass {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        //A. acelerador. --> B motor
        //Motor observa --> Acelerador, Observer y el sujeto (Observable)
        //Acelrador(Subject) observado, MOtor Observador
        
        Engine v8 = new Engine ();
        
        Throttle x = new Throttle ();
        
        x.linkObserver(v8);
        
        x.stepThrottle();
    }
    
}
