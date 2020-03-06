// SnakeGame.h

// In function handles f is for food objects and s is for snake s objects
#include "GameObject.h"
#include <deque>
using std::deque;

		void moveSnake(int newdir, deque <GameObject> s);
	
		int collisionSelf(deque <GameObject> s); //checks collisions with snake body. returns 1 if collision
		
		int collisionWall(deque <GameObject> s);//checks collisions with walls. returns 1 if collision
		
		int eating(deque <GameObject> s, GameObject f); //checks for collision with food and updates score
	
		void createFood(GameObject f);
		
		void drawScreen(deque <GameObject> s, GameObject f);
		
		int handleInputs(); //checks button input and returns an int direction for snake 0: left, 1: right, 2: down, 3: up 
		
		void gameSetup(deque <GameObject> s, GameObject f);
		
		void gamePlay(deque <GameObject> s, GameObject f);
		
		void gameEnd(); // handles losing 

