// SnakeGame.h

// In function handles f is for food objects and s is for snake s objects
#include "GameObject.h"

class SnakeGame{
	private:
	
	public:
		void moveSnake(int newdir, queue <GameObject> s);
	
		void collisionDetection(queue <GameObject> s); //checks collisions with walls and snake body
	
		int eating(queue <GameObject> s, GameObject f); //checks for collision with food and updates score
	
		void createFood(GameObject f);
		
		void drawScreen(queue <GameObject> s, GameObject f);
		
		void handleInputs();
		
		void gameSetup();
		
		void gamePlay();
		
		void gameEnd(); // handles losing 
};

