// GameObject.cpp

#include GameObject.h

	GameObject::GameObject()
	{
		x = 0;
		y = 0;
		width = 4;
		height = 2;
		symbol = 'r';
	}
	
	GameObject::GameObject(int xi, int yi)
	{
		x = xi;
		y = yi;
		width = 4;
		height = 2;
		symbol = 'r';
	}

	GameObject::GameObject(int xi, int yi, int widthi, int heighti, char symboli)
	{
		x = xi;
		y = yi;
		width = widthi;
		height = heighti;
		symbol = symboli;
	}
	
	void setx(int xnew)
	{
		x = xnew;
	}
	
	int getx()
	{
		return x;
	}
		
	void sety(int ynew)
	{
		y = ynew;
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
		
	char getsymbol()
	{
		return symbol;
	}
