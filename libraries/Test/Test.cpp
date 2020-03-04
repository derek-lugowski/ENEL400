//Test.cpp

#include <Controller.h>
#include "MCUFRIEND_kbv.h"


#define BLACK 0x0000
#define BLUE 0x001F
#define WHITE 0xFFFF
#define RED 0xF800

void Draw_test_screen(int* button_states, MCUFRIEND_kbv tft);
void Update_test_screen(int* button_states, MCUFRIEND_kbv tft);

int Test(Controller controller, MCUFRIEND_kbv tft)
{
  int* buttons_state;
  buttons_state = controller.read_buttons();
 // MCUFRIEND_kbv tft;
  //uint16_t ID = tft.readID();
 // tft.begin(ID);
  Draw_test_screen(buttons_state, tft);
  
  unsigned long last_frame_time = millis();
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  while(1)
  {
    buttons_state = controller.read_buttons();
    Update_test_screen(buttons_state, tft);
    
    // printing time since last frame
    tft.setCursor(50, 50);
    tft.fillRect(50, 50, 60, 22, RED);
    tft.print(millis() - last_frame_time);
    
    
    // printing FPS
    tft.setCursor(50, 80);
    tft.fillRect(50, 80, 60, 22, RED);
    tft.print(1000 / (millis() - last_frame_time));
    last_frame_time = millis();
  }
}







 // dimensions are 320 x 480
void Draw_test_screen(int* button_states, MCUFRIEND_kbv tft)
{
  tft.fillScreen(BLACK);
  for(int i =0; i < 6; i++)
  {
    if(button_states[i] == HIGH)
    {
      tft.fillCircle(160, 40 + i*80, 25, WHITE);
    }
    else
    {
      tft.drawCircle(160, 40 + i*80, 25, WHITE);
    }
  }  
}


void Update_test_screen(int* button_states, MCUFRIEND_kbv tft)
{
  for(int i =0; i < 6; i++)
  {
    if(button_states[i] == HIGH)
    {
      tft.fillCircle(160, 40 + i*80, 25, WHITE);
    }
    else
    {
      tft.fillCircle(160, 40 + i*80, 24, BLACK);
      tft.drawCircle(160, 40 + i*80, 25, WHITE);
    }
  }
  
}
