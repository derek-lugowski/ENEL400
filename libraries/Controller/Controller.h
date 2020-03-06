//Controller.h
/*
 * This is a class for reading the 6 button controller.
 * 
 * int* button_states = Controller.read_buttons();
 *
 * button_states is a pointer to an array of 6 ints that corrispond to each of the buttons
 * button_states --> {A, B, U, D, L, R}
 *
 * checks the value of the buttons initialized with the Controler object.
 * This will check the state of the button and debounce it.
 * This should be called every game loop to check the button state.
 * May not update right away after button pressing due to debouncing.
 * 
 *
 * void start(int* button_pins);
 *
 * This function initializes the Controller object by:
 * 1. setting the pins that the controller in connected to on the Arduino
 * 2. setting the pinmode for the pins to INPUT
 *
 */
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

//#include "Arduino.h"


class Controller{
  
  public:
    int buttons[6];
    int buttons_state[6];
    int buttons_last_read[6];
    unsigned long lastDebounceTime[6];
    const unsigned long debounce_delay;
    
  //public:
  
    Controller();
    
    Controller(int A, int B, int U, int D, int L, int R);
    
    int* read_buttons(); // reads all buttons. returns buttons_state
    
    void start(int* button_pins);
};


#endif
