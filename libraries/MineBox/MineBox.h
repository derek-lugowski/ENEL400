//MineBox.h

#ifndef MINEBOX_INCLUDED
#define MINEBOX_INCLUDED

#include <MCUFRIEND_kbv.h>
#include <Controller.h>
#include <Position.h>

class MineBox
{
  
  private:
    int x;
    int y;
    Position mines[100];
    
    
  public:
    MineBox(int xi, int yi);
    
    void draw(int color, MCUFRIEND_kbv tft);
    
    void resolve_inputs(int* previous_buttons, int* buttons, MCUFRIEND_kbv);
    
    void move(int i, MCUFRIEND_kbv tft);
    
    void pickMines(int amount);
    
    void drawMines(int amount, MCUFRIEND_kbv tft, int color);

};


#endif
