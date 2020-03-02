// SnakeGame.cpp

#include "SnakeGame.h"

int upButton; 
int downButton;
int leftButton;
int rightButton;
		
void moveSnake(int xcd, int ycd, int newdir, GameObject *s)
{
}	
	
void collisionDetection(GameObject *s); //checks collisions with walls and snake body
	
void eating(GameObject *s, GameObject f); //checks for collision with food and updates score
	
void createFood(GameObject f);
		
void drawScreen(GameObject *s, GameObject f);
		
void handleInputs();
		
void gameSetup();
		
void gamePlay();
		
void gameEnd(); // handles losing 

int main(void){
	return 1;
}
