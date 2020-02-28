//Snake.cpp
// 320 x 480 screen size 

#include GameObject.h
// need to include drawing library

//constant for snake colour??

	GameObject::GameObject()
	{
		int x = 24; //snakes starts in the middle of screen as default 
		int y = 16;
		int width = 1;
		int height = 1;
	}	
	
	GameObject::GameObject(int startX, int startY)
	{
		int x = startX;
		int y = startY;
		int width = 1;
		int height = 1;
	}
		
	void setx(int xnew)
	{
		int x = xnew;
	}
	
	int getx()
	{
		return x;
	}
		
	void sety(int ynew)
	{
		int y = ynew;
	}
	
	int gety()
	{
		return y;
	}
		
	void movesnake(int dx, int dy)
	{
		x += dx;
		y += dy;
	}
	
	int getwidth()
	{
		return width;
	}
		
	int getheight()
	{
		return height;
	}
		
	void drawsnake()
	{
		//code to draw a rectangle of height and length
	}