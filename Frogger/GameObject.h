// GameObject.h

class GameObject{
	protected:
		int x; //left most position for square/rec or centre position for circle
		int y; //top most position for square/rec or centre position for circle
		int width;
		int height; 
		char symbol; // char to define shape of object ie r = rec s = square c = circle t =triangle 
		
	public:
		GameObject();
		GameObject(int xi, int yi);
		GameObject(int xi, int yi, int widthi, int heighti, char symboli);
		
		void setx(int xnew);
		int getx();
		
		void sety(int ynew);
		int gety();
		
		int getwidth();
		
		int getheight();
		
		char getsymbol();
}