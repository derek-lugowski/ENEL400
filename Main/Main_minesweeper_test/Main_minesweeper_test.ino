//#include <Test.h>
//#include <GameObject.h>
//#include <SnakeGame.h>
#include <Minesweeper.h>

#include <Controller.h>
Controller controller;

//#include "Adafruit_GFX.h"
#include "MCUFRIEND_kbv.h"
MCUFRIEND_kbv tft; // initialize tft object
/*
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
*/


//controller.start();
void setup() {
  Serial.begin(9600); // start communication with serial port
  
  int button_pins[] = {33, 31, 29, 27, 25, 23};
  controller.start(button_pins);
  controller.read_buttons();
  
  uint16_t ID = tft.readID(); // getting id from screen
  tft.begin(ID);
  
  //tft.fillScreen(DARKGREEN);
//  int16_t w = tft.width(); // get width and length from tft object and print to serial port
//  int16_t h = tft.height();
//  Serial.print("width is: "); 
//  Serial.println(w); // 320
//  Serial.println(h); // 480
//  tft.fillScreen(RED);
}

void loop() {
  //Serial.println("calling Minesweeper");
  Minesweeper(controller, tft);
  delay(100);
}
