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
		int direction = 0; // initially moving left
	}	
	
	GameObject::GameObject(int startX, int startY)
	{
		int x = startX;
		int y = startY;
		int width = 1;
		int height = 1;
		int direction = 0; // initially moving left
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
		
	int getwidth()
	{
		return width;
	}
		
	int getheight()
	{
		return height;
	}
	
	void setdirection(int newdir);
	{
		direction = newdir;
	}
	
	int getdirection()
	{
		return direction;
	}
	
	void movesnake(void)
	{
		if(direction = 0){
			x = x - 1; //moves snake 10 pixels left
		}else if(direction = 1){
			x = x + 1; //moves snake 10 pixels right 
		}else if(direction = 2){
			y = y - 1; //moves snake 10 pixels down
		}else if(direction = 3){
			y = y + 1; //moves snake 10 pixels up
		}else{
			x = x;
			y = y;
		}
	}
	
	void drawsnake(int colour)
	{
		//code to draw a rectangle of height and length
	}