//Controller.cpp

#include "Controller.h"
#include "Arduino.h"
Controller::Controller()
{
  int buttons[6] = {23, 25, 27, 29, 31, 33};
  int buttons_state [6] = {LOW, LOW, LOW, LOW, LOW, LOW};
  int buttons_current_read[6] = {LOW, LOW, LOW, LOW, LOW, LOW};
  unsigned long lastDebounceTime[6] = {0, 0, 0, 0, 0, 0};
  const int debounce_delay = 5;
}

Controller::Controller(int A, int B, int U, int D, int L, int R)
{
  int buttons[6] = {A, B, U, D, L, R};
  int buttons_state [6] = {LOW, LOW, LOW, LOW, LOW, LOW};
  int buttons_last_read[6] = {LOW, LOW, LOW, LOW, LOW, LOW};
  unsigned long lastDebounceTime[6] = {0, 0, 0, 0, 0, 0};
  const int debounce_delay = 5;
}

int* Controller::read_buttons()
{
  for(int i = 0; i < 6; i++)
  {
    int reading = digitalRead(buttons[i]);
    
    if(reading != buttons_last_read[i])
    {
      lastDebounceTime[i] = millis();
    }
    
    if((millis() - lastDebounceTime[i]) > debounce_delay)
    {
      if(reading != buttons_state[i])
      {
        buttons_state[i] = reading;
      }
    }
    buttons_last_read[i] = reading;
  }
  return buttons_state;
}


void Controller::start(int* button_pins)
{
  for(int i = 0; i < 6; i++)
  {
    buttons[i] = button_pins[i];
    pinMode(buttons[i], INPUT);
  }
}
