//Minesweeper.cpp

#include <Minesweeper.h>
#include <Controller.h>
#include <MCUFRIEND_kbv.h>

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


void drawScreen(MCUFRIEND_kbv tft); //initial screen draw



void Minesweeper(Controller controller, MCUFRIEND_kbv tft) //Main game loop for minesweeper.
{
  int* button_states;
  button_states = controller.read_buttons();
  tft.setRotation(1);
  drawScreen(tft);
  //cursor Cursor(7, 11);
  
  while(1) // main game loop
  {
    
    
    
    if(1){break;}
  }
}


//screen size = 320 x 480
//using 20x20 for square sizes --> 16x24 grid
void drawScreen(MCUFRIEND_kbv tft) // initial draw screen
{
  tft.fillScreen(ORANGE);
  for(int x = 0; x < 24; x++)
  {
    for(int y = 0; y < 16; y++)
    {
      tft.drawRect(20*x, 20*y, 20, 20, BLACK);
    }
  }
  
  //tft.drawRect(20*5, 20*6, 20, 20, WHITE);
  
  
  
  //screen drawing tests:
  
  
  //tft.drawRect(20*5, 20*7, 20, 20, GREEN);
  
  //tft.fillScreen(LIGHTGREY);
  //tft.fillRect(100, 100, 20, 20, WHITE);
  //tft.fillRect(100, 130, 20, 20, WHITE);
  //tft.drawRect(100, 130, 20, 20, BLACK);
  //tft.drawRect(100, 160, 20, 20, BLACK);
  //tft.fillRect(100, 190, 20, 40, ORANGE);
  ////tft.drawRect(100, 190, 20, 40, BLACK);
  //tft.drawFastVLine(100, 210, 20, BLACK);
  //tft.setCursor(200, 100);
  //tft.setTextColor(BLACK);
  //tft.setTextSize(2);
  //tft.print("hello world");
  //tft.drawRect(0, 0, 20, 20, ORANGE);
  //tft.fillRect(1, 1, 18, 18, BLACK);
}
