// SnakeGame.h

// In function handles f is for food objects and s is for snake s objects

#include GameObject.h

class SnakeGame{
	
	public:
		void moveSnake();
	
		void collisionDetection(GameObject *s); //checks collisions with walls and snake body
	
		void eating(GameObject *s, GameObject f); //checks for collision with food and updates score
	
		void createFood(GameObject f);
		
		void drawScreen(GameObject s*, GameObject f);
		
		void handleInputs();
		
		void gameSetup();
		
		void gamePlay();
		
		void gameEnd(); // handles losing 
}

