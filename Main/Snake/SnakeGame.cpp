// SnakeGame.cpp

#include SnakeGame.h
#include GameObject.h

int upButton; // not sure if buttons are ints???
int downButton;
int leftButton;
int rightButton;
		
GameObject snake[100];
GameObject food;

void moveSnake();
	
void collisionDetection(GameObject *s); //checks collisions with walls and snake body
	
void eating(GameObject *s, GameObject f); //checks for collision with food and updates score
	
void createFood(GameObject f);
		
void drawScreen(GameObject s*, GameObject f);
		
void handleInputs();
		
void gameSetup();
		
void gamePlay();
		
void gameEnd(); // handles losing 
