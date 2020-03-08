//MineBox.cpp

#include <MineBox.h>
#include <MCUFRIEND_kbv.h>
#include <Controller.h>
#include <Position.h>

#define BLACK 0x0000
#define NAVY 0x000F
#define DARKGREEN 0x03E0
#define DARKCYAN 0x03EF
#define MAROON 0x7800
#define PURPLE 0x780F
#define OLIVE 0x7BE0
#define LIGHTGREY 0xC618
#define DARKGREY 0x7BEF
#define BLUE 0x001F
#define GREEN 0x07E0
#define CYAN 0x07FF
#define RED 0xF800
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define ORANGE 0xFD20
#define GREENYELLOW 0xAFE5
#define PINK 0xF81F

MineBox::MineBox(int xi, int yi)
{
  x = xi;
  y = yi;  
}


void MineBox::draw(int color, MCUFRIEND_kbv tft)
{
  tft.drawRect(20*x, 20*y, 20, 20, color);
}


void MineBox::resolve_inputs(int* previous_buttons, int* buttons, MCUFRIEND_kbv tft) //controller order: A, B, U, D, L, R
{
  for(int i = 0; i < 6; i++)
  {
    if(previous_buttons[i] != buttons[i] && buttons[i] == LOW)
    {
      move(i, tft);
    }
  }
}


void MineBox::move(int i, MCUFRIEND_kbv tft)
{
  if(i == 2)
  {
    if(y>0)
    {
      draw(BLACK, tft);
      y--;
      draw(WHITE, tft);
    }
  }
  else if(i == 3)
  {
    if(y<15)
    {
      draw(BLACK, tft);
      y++;
      draw(WHITE, tft);
    }
  }
  else if(i == 4)
  {
    if(x>0)
    {
      draw(BLACK, tft);
      x--;
      draw(WHITE, tft);
    }
  }
  else if(i == 5)
  {
    if(x< 23)
    {
      draw(BLACK, tft);
      x++;
      draw(WHITE, tft);
    }
  }
  //else if(i == 0)
  //{
    
  //}
}

void MineBox::pickMines(int amount)
{
  randomSeed(analogRead(8));
  for(int i = 0; i < amount; i++)
  {
    mines[i].x = int(random(0, 24));
    mines[i].y = int(random(0, 16));
  }
  
}

void MineBox::drawMines(int amount, MCUFRIEND_kbv tft, int color)
{
  for(int i = 0; i < amount; i++)
  {
    tft.fillCircle(20*mines[i].x +10, 20*mines[i].y+10, 9, color);
  }
}
