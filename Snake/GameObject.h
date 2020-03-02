//GameObject.h

class GameObject{
	private:
		int x; //left most position for square/rec or centre position for circle
		int y; //top most position for square/rec or centre position for circle
		int width; // number of pixels for the length of each block in the snake
		int height; // number of pixels for the width of each block in the snake (same as width of snake)
		int direction; // way the snake is moving, 0: left, 1: right, 2: down, 3: up 
	
	public:
		GameObject();
		GameObject(int startX, int startY);
		
		void setx(int xnew);
		int getx();
		
		void sety(int ynew);
		int gety();
		
		int getwidth();
		
		int getheight();
		
		void setdirection(int newdir);
		int getdirection();
		
		void movesnake();
		
		void drawsnake(int colour); // not sure if colour is an int???
};