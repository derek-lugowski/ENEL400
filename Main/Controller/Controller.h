//Controller.h
/*
 * This is a class for reading the 6 button controller.
 * 
 * Controller.read_buttons();
 * checks the value of the buttons initialized with the Controler object.
 * This will check the state of the button and debounce it.
 * This should be called every game loop to check the button state.
 * May not update right away after button pressing due to debouncing.
 * 
 */
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
class Controller{
  private:
    int buttons[6];
    int buttons_state[6];
    int buttons_last_read[6];
    unsigned long lastDebounceTime[6];
    const unsigned long debounce_delay;
  public:
    Controller();
    
    Controller(int A, int B, int U, int D, int L, int R);
    
    int* read_buttons(); // reads all buttons. returns buttons_state
    
    void start();
};


#endif
