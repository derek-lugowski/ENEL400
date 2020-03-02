// Frog.h

class Frog: public GameObject{
	private:
		int startX;
		int startY;
		int lives;
	
	public:
		Frog();
		Frog(int xi, int yi, int liv);
		
		void setStartX(int initx);
		int getStartX(void);
		
		void setStarty(int inity);
		int getStartY(void);
		
		void setLives(int livs);
		int getLives(void);
		
		void move(int dx, int dy);
		
		void die(void);
		
		void resetFrog(void);
}
		
		