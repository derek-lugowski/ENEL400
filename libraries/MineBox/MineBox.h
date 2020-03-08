//MineBox.h

#ifndef MINEBOX_INCLUDED
#define MINEBOX_INCLUDED

#include <MCUFRIEND_kbv.h>
#include <Controller.h>
#include <Block.h>

class MineBox
{
  
  private:
    int x;
    int y;
    Block grid[24][16];
    
    
  public:
    MineBox(int xi, int yi);
    
    void fill(int color, MCUFRIEND_kbv tft);
    void fill(int xnew, int ynew, int color, MCUFRIEND_kbv tft);
    
    void draw(int color, MCUFRIEND_kbv tft);
    
    int resolve_inputs(int* previous_buttons, int* buttons, MCUFRIEND_kbv);
    
    int move(int i, MCUFRIEND_kbv tft);
    
    void pickMines(int amount);
    
    void drawMines(MCUFRIEND_kbv tft, int color);
    
    int testBlock(int x, int y, MCUFRIEND_kbv tft);
    
    void drawFlag(MCUFRIEND_kbv tft);

};


#endif
