//Snake.cpp
// 320 x 480 screen size 

#include <GameObject.h>
#include "MCUFRIEND_kbv.h"


//constant for snake colour??

	GameObject::GameObject()
	{
		x = 24; //snakes starts in the middle of screen as default 
		y = 16;
		width = 1;
		height = 1;
		//direction = 0; // initially moving left
	}	
	
	GameObject::GameObject(int startX, int startY)
	{
		x = startX;
		y = startY;
		width = 1;
		height = 1;
		//direction = 0; // initially moving left
	}
		
	void GameObject::setx(int xnew)
	{
		x = xnew;
	}
	
	int GameObject::getx()
	{
		return x;
	}
		
	void GameObject::sety(int ynew)
	{
		y = ynew;
	}
	
	int GameObject::gety()
	{
		return y;
	}
		
	int GameObject::getwidth()
	{
		return width;
	}
		
	int GameObject::getheight()
	{
		return height;
	}
	
/*	void GameObject::setdirection(int newdir)
	{
		direction = newdir;
	}
	
	int GameObject::getdirection()
	{
		return direction;
	}
	
	void GameObject::movesnake(void)
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
	} */
	
	void GameObject::draw(int colour, MCUFRIEND_kbv tft)
	{
      tft.fillRect(x,y,width,height, colour);
	}
