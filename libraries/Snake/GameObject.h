//GameObject.h
#ifndef GAME_OBJECT_INCLUDED
#define GAME_OBJECT_INCLUDED

#include "MCUFRIEND_kbv.h"

class GameObject{
	private:
		int x; //left most position for square/rec or centre position for circle
		int y; //top most position for square/rec or centre position for circle
		int width; // number of pixels for the length of each block in the snake
		int height; // number of pixels for the width of each block in the snake (same as width of snake)
	
	public:
		GameObject();
		GameObject(int startX, int startY);
		
		void setx(int xnew);
		int getx();
		
		void sety(int ynew);
		int gety();
		
		int getwidth();
		
		int getheight();
		
		//void setdirection(int newdir);
		//int getdirection();
		
		void draw(int colour, MCUFRIEND_kbv tft); // not sure if colour is an int???
};


#endif
