//MineBox.cpp

#include <MineBox.h>
#include <MCUFRIEND_kbv.h>
#include <Controller.h>
#include <Block.h>
#include <MemoryFree.h>

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
  for(int i = 0; i<24; i++)
  {
    for(int j = 0; j<16; j++)
    {
      grid[i][j] = Block();
    }
  }
}

void MineBox::fill(int color, MCUFRIEND_kbv tft)
{
  tft.fillRect(20*x+1, 20*y+1, 18, 18, color);
}
void MineBox::fill(int xnew, int ynew, int color, MCUFRIEND_kbv tft)
{
  tft.fillRect(20*xnew+1, 20*ynew+1, 18, 18, color);
}

void MineBox::draw(int color, MCUFRIEND_kbv tft)
{
  tft.drawRect(20*x, 20*y, 20, 20, color);
}


int MineBox::resolve_inputs(int* previous_buttons, int* buttons, MCUFRIEND_kbv tft) //controller order: A, B, U, D, L, R
{
  //Serial.println("just entered box.resove_inputs");
  for(int i = 0; i < 6; i++)
  {
    //Serial.print("in for loop with i = ");
    //Serial.println(i);
    if(previous_buttons[i] != buttons[i] && buttons[i] == LOW) // testing if button was pressed
    {
      //Serial.print("just caught button pressed with i = ");
      //Serial.println(i);
      //Serial.println("calling move");
      return(move(i, tft));//rv from move decides if game is over or not.
    }
  }
  return 0;
}


int MineBox::move(int i, MCUFRIEND_kbv tft)
{
    //Serial.println("just entered move");
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
  else if(i == 0)
  {
    if(testBlock(x, y, tft) == 1)
    {
      return 1;//game over
    }
  }
  else if(i == 1)
  {
    drawFlag(tft);
  }
  return 0; //game not over
}

void MineBox::pickMines(int amount)
{
  randomSeed(analogRead(8));
  for(int i = 0; i < amount; i++)
  {
    grid[int(random(0,24))][int(random(0,16))].is_mine = true;
  }
  
}

void MineBox::drawFlag(MCUFRIEND_kbv tft)
{
  if(grid[x][y].is_tested == false)
    {
    if(grid[x][y].is_flagged == false)
    {
      tft.fillCircle(20*x+10, 20*y+10, 5, BLUE);
      grid[x][y].is_flagged = true;
    }
    else
    {
      fill(ORANGE, tft);
      grid[x][y].is_flagged = false;
    }
  }
}

void MineBox::drawMines(MCUFRIEND_kbv tft, int color)
{
  for(int i = 0; i<24; i++)
  {
    for(int j = 0; j<16; j++)
    {
      if(grid[i][j].is_mine == true)
        tft.fillCircle(20*i + 10, 20*j+10,9,color);
    }
  }
}

int MineBox::testBlock(int xtest, int ytest, MCUFRIEND_kbv tft) // recursive function to test for mines on a block
{
  if(xtest < 0 or ytest < 0 or xtest > 23 or ytest > 15) // if block is not on screen (recessary for recursive algorithm)
    return 0;
    
  if(grid[xtest][ytest].is_tested == true) // if block is already tested, don't test again.
    return 0;
  
  if(grid[xtest][ytest].is_mine == true) // if there is a mine on the spot 
  {
    return 1;
  }
  
  int count = 0; // nested for loop to count mines around selsected block
  for(int i = -1; i<2; i++)
  {
    for(int j = -1; j<2; j++)
    {
      if(xtest+i<0 or ytest+j < 0 or xtest+i > 23 or ytest+j > 15)
        continue;
      if(grid[xtest+i][ytest+j].is_mine == true)
        count++;
    }
  }
  
  grid[xtest][ytest].is_tested = true;
  if(count != 0) // print the number of adjacent mines
  {
    fill(xtest, ytest, LIGHTGREY, tft);
    tft.setCursor(20*xtest+5, 20*ytest+3);
    tft.setTextSize(2);
    tft.setTextColor(BLACK);
    tft.print(count);
  }
  else if(freeMemory() < 500)     // if memory runs out on the stack, breaks recursive loop.
    fill(xtest,ytest,LIGHTGREY,tft);
  else      //recrusive part of the algorthim
  {
    fill(xtest, ytest, LIGHTGREY,tft);
    
      testBlock(xtest+1, ytest, tft);
      testBlock(xtest-1, ytest, tft);
      testBlock(xtest, ytest+1, tft);
      testBlock(xtest, ytest-1, tft);
      testBlock(xtest-1, ytest-1, tft);
      testBlock(xtest-1, ytest+1, tft);
      testBlock(xtest+1, ytest-1, tft);
      testBlock(xtest+1, ytest+1, tft);
  }
  return 0;
}

