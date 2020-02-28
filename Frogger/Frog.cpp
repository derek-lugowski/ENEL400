// Frog.cpp

# include Frog.h

	Frog::Frog()
	{
		startX = 50; // need to change based on screen
		startY = 0; // need to change based on screen 
		lives = 3;
	}
		
	Frog::Frog(int xi, int yi, int liv)
	{
		startX = xi;
		startY = yi;
		lives = liv;
	}
		
	void setStartX(int initx)
	{
		startX = initx;
	}
	
	int getStartX(void)
	{
		return startX;
	}
	
	void setStarty(int inity)
	{
		startY = inity;
	}
	
	
	int getStartY(void)
	{
		return startY;
	}
	
	void setLives(int livs)
	{
		lives = livs;
	}
	
	int getLives(void)
	{
		return lives;
	}
		
	void move(int dx, int dy)
	{
		x += dx;
		y += dy;
	}
		
	void die(void)
	{
		lives -= lives;
		resetFrog();
	}
		
	void resetFrog(void)
	{
		x = startX;
		y = startY;
	}