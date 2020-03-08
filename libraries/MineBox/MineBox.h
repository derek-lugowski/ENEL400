//MineBox.h

#ifndef MINEBOX_INCLUDED
#define MINEBOX_INCLUDED

#include <MCUFRIEND_kbv.h>
#include <Controller.h>

class MineBox
{
  
  private:
    int x;
    int y;
    
  public:
    MineBox(int xi, int yi);
    
    void draw(int color, MCUFRIEND_kbv tft);
    
    void move(int* previous_buttons, int* buttons, MCUFRIEND_kbv);
    
    void move_draw(int i, MCUFRIEND_kbv tft);

};


#endif
