//Technical support:goodtft@163.com
// Breakout/Arduino UNO pin usage:
// LCD Data Bit :   7   6   5   4   3   2   1   0
// Uno dig. pin :   7   6   5   4   3   2   9   8
// Uno port/pin : PD7 PD6 PD5 PD4 PD3 PD2 PB1 PB0
// Mega dig. pin:  29  28  27  26  25  24  23  22
#define LCD_RD   A0
#define LCD_WR   A1     
#define LCD_RS   A2        
#define LCD_CS   A3       
#define LCD_REST A4

void Lcd_Writ_Bus(unsigned char d)
{
 PORTD = (PORTD & B00000011) | ((d) & B11111100); 
 PORTB = (PORTB & B11111100) | ((d) & B00000011); 
 *(portOutputRegister(digitalPinToPort(LCD_WR))) &=  ~digitalPinToBitMask(LCD_WR);
 *(portOutputRegister(digitalPinToPort(LCD_WR)))|=  digitalPinToBitMask(LCD_WR);
}


void Lcd_Write_Com(unsigned char VH)  
{   
  *(portOutputRegister(digitalPinToPort(LCD_RS))) &=  ~digitalPinToBitMask(LCD_RS);//LCD_RS=0;
  Lcd_Writ_Bus(VH);
}

void Lcd_Write_Data(unsigned char VH)
{
  *(portOutputRegister(digitalPinToPort(LCD_RS)))|=  digitalPinToBitMask(LCD_RS);//LCD_RS=1;
  Lcd_Writ_Bus(VH);
}


void Lcd_Write_Com_Data(unsigned char com,unsigned char dat)
{
  Lcd_Write_Com(com);
  Lcd_Write_Data(dat);
}
void LCD_WriteReg(unsigned char com,unsigned int dat)
{
  Lcd_Write_Com(com);
  Lcd_Write_Data(dat);
 }
void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2)
{
  Lcd_Write_Com(0x2a);
  Lcd_Write_Data(x1>>8);
  Lcd_Write_Data(x1);
  Lcd_Write_Data(x2>>8);
  Lcd_Write_Data(x2);
  
  Lcd_Write_Com(0x2b);
  Lcd_Write_Data(y1>>8);
  Lcd_Write_Data(y1);
  Lcd_Write_Data(y2>>8);
  Lcd_Write_Data(y2);
  Lcd_Write_Com(0x2c);              
}

void Lcd_Init(void)
{
  digitalWrite(LCD_REST,HIGH);
  delay(50); 
  digitalWrite(LCD_REST,LOW);
  delay(150);
  digitalWrite(LCD_REST,HIGH);
  delay(150);

  digitalWrite(LCD_CS,HIGH);
  digitalWrite(LCD_WR,HIGH);
  digitalWrite(LCD_CS,LOW);  //CS

  Lcd_Write_Com(0XF9);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0x08);
  
  Lcd_Write_Com(0xC0);
  Lcd_Write_Data(0x19);//VREG1OUT POSITIVE
  Lcd_Write_Data(0x1a);//VREG2OUT NEGATIVE
  
  Lcd_Write_Com(0xC1);
  Lcd_Write_Data(0x45);//VGH,VGL    VGH>=14V.
  Lcd_Write_Data(0x00);
  
  Lcd_Write_Com(0xC2);
  Lcd_Write_Data(0x33);
  
  Lcd_Write_Com(0XC5);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0x28);//VCM_REG[7:0]. <=0X80.
    
  Lcd_Write_Com(0xB1);//OSC Freq set.
  Lcd_Write_Data(0x90);//0xA0=62HZ,0XB0 =70HZ, <=0XB0.
  Lcd_Write_Data(0x11);
  
  Lcd_Write_Com(0xB4);
  Lcd_Write_Data(0x02); //2 DOT FRAME MODE,F<=70HZ.
  
  Lcd_Write_Com(0xB6);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0x42);//0 GS SS SM ISC[3:0];
  Lcd_Write_Data(0x3B);
    
  Lcd_Write_Com(0xB7);
  Lcd_Write_Data(0x07);
  
  Lcd_Write_Com(0xE0);
  Lcd_Write_Data(0x1F);
  Lcd_Write_Data(0x25);
  Lcd_Write_Data(0x22);
  Lcd_Write_Data(0x0B);
  Lcd_Write_Data(0x06);
  Lcd_Write_Data(0x0A);
  Lcd_Write_Data(0x4E);
  Lcd_Write_Data(0xC6);
  Lcd_Write_Data(0x39);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0x00);
  
  Lcd_Write_Com(0XE1);
  Lcd_Write_Data(0x1F);
  Lcd_Write_Data(0x3F);
  Lcd_Write_Data(0x3F);
  Lcd_Write_Data(0x0F);
  Lcd_Write_Data(0x1F);
  Lcd_Write_Data(0x0F);
  Lcd_Write_Data(0x46);
  Lcd_Write_Data(0x49);
  Lcd_Write_Data(0x31);
  Lcd_Write_Data(0x05);
  Lcd_Write_Data(0x09);
  Lcd_Write_Data(0x03);
  Lcd_Write_Data(0x1C);
  Lcd_Write_Data(0x1A);
  Lcd_Write_Data(0x00);
  
  Lcd_Write_Com(0XF1);
  Lcd_Write_Data(0x36);
  Lcd_Write_Data(0x04);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0x3C);
  Lcd_Write_Data(0x0F);
  Lcd_Write_Data(0x0F);
  Lcd_Write_Data(0xA4);
  Lcd_Write_Data(0x02);
  
  Lcd_Write_Com(0XF2);
  Lcd_Write_Data(0x18);
  Lcd_Write_Data(0xA3);
  Lcd_Write_Data(0x12);
  Lcd_Write_Data(0x02);
  Lcd_Write_Data(0x32);
  Lcd_Write_Data(0x12);
  Lcd_Write_Data(0xFF);
  Lcd_Write_Data(0x32);
  Lcd_Write_Data(0x00);
  
  Lcd_Write_Com(0XF4);
  Lcd_Write_Data(0x40);
  Lcd_Write_Data(0x00);
  Lcd_Write_Data(0x08);
  Lcd_Write_Data(0x91);
  Lcd_Write_Data(0x04);
  
  Lcd_Write_Com(0XF8);
  Lcd_Write_Data(0x21);
  Lcd_Write_Data(0x04);
  
  Lcd_Write_Com(0x36);
  Lcd_Write_Data(0xC8);
  
  Lcd_Write_Com(0x3A);
  Lcd_Write_Data(0x55);
  
  Lcd_Write_Com(0x11);
  delay(120);
  //Lcd_Write_Com(0x21);
  Lcd_Write_Com(0x29);  
}

void H_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c)                   
{  
  unsigned int i,j;
  Lcd_Write_Com(0x02c); //write_memory_start
  digitalWrite(LCD_RS,HIGH);
  digitalWrite(LCD_CS,LOW);
  l=l+x;
  Address_set(x,y,l,y);
  j=l*2;
  for(i=1;i<=j;i++)
  {
    Lcd_Write_Data(c);
  }
  digitalWrite(LCD_CS,HIGH);   
}

void V_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c)                   
{ 
  unsigned int i,j;
  Lcd_Write_Com(0x02c); //write_memory_start
  digitalWrite(LCD_RS,HIGH);
  digitalWrite(LCD_CS,LOW);
  l=l+y;
  Address_set(x,y,x,l);
  j=l*2;
  for(i=1;i<=j;i++)
  { 
    Lcd_Write_Data(c);
  }
  digitalWrite(LCD_CS,HIGH);   
}

void Rect(unsigned int x,unsigned int y,unsigned int w,unsigned int h,unsigned int c)
{
  H_line(x  , y  , w, c);
  H_line(x  , y+h, w, c);
  V_line(x  , y  , h, c);
  V_line(x+w, y  , h, c);
}

void Rectf(unsigned int x,unsigned int y,unsigned int w,unsigned int h,unsigned int c)
{
  unsigned int i;
  for(i=0;i<h;i++)
  {
    H_line(x  , y  , w, c);
    H_line(x  , y+i, w, c);
  }
}
int RGB(int r,int g,int b)
{return r << 16 | g << 8 | b;
}
void LCD_Clear(unsigned int j)                   
{  
  unsigned int i,m;
 Address_set(0,0,320-1,480-1);
  //Lcd_Write_Com(0x02c); //write_memory_start
  //digitalWrite(LCD_RS,HIGH);
  digitalWrite(LCD_CS,LOW);


  for(i=0;i<480;i++)
    for(m=0;m<320;m++)
    {
      Lcd_Write_Data(j>>8);
      Lcd_Write_Data(j);

    }
  digitalWrite(LCD_CS,HIGH);   
}

void setup()
{
  for(int p=0;p<10;p++)
  {
    pinMode(p,OUTPUT);
  }
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  Lcd_Init();
 //LCD_Clear(0xf800);
}

void loop()
{  
   LCD_Clear(0xffff);
   LCD_Clear(0x0000);
   LCD_Clear(0xf800);
   LCD_Clear(0x07E0);
   LCD_Clear(0x001F);
  /*   
  for(int i=0;i<1000;i++)
  {
    Rect(random(300),random(300),random(300),random(300),random(65535)); // rectangle at x, y, with, hight, color
  }*/
  
//  LCD_Clear(0xf800);
}
