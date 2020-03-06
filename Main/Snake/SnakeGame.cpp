// SnakeGame.cpp

#include "SnakeGame.h"
//#include "GameObject.h"
#include <queue>
#include <stdlib.h>

using std::queue;

int upButton; 
int downButton;
int leftButton;
int rightButton;

int score;
		

void moveSnake(int newdir, queue <GameObject> s){
	if(newdir = 0){
		s.push(GameObject(s.back().getx() - 1,s.back().gety())); // adds new block to the left of the snake
		s.pop(); //removes last block
	}else if(newdir = 1){
		s.push(GameObject(s.back().getx() + 1,s.back().gety())); // adds new block to the right of the snake
		s.pop();
	}else if(newdir = 2){
		s.push(GameObject(s.back().getx(),s.back().gety()-1)); // adds new block to down side of the snake
		s.pop();
	}else if(newdir = 3){
		s.push(GameObject(s.back().getx(),s.back().gety()+1)); // adds new block to up side of the snake
		s.pop();
	}//need an else??
}
	
void collisionDetection(queue <GameObject> s){
}
	
int eating(queue <GameObject> s, GameObject f, int dir){
	if(s.back().getx() == f.getx() && s.back().gety() == f.gety()){//checks to see if head is in the same place as food
		score += 10;
		if(dir = 0){ //adds new block in correct direction
			s.push(GameObject(s.back().getx() - 1,s.back().gety())); // adds new block to the left of the snake
		}else if(dir = 1){
			s.push(GameObject(s.back().getx() + 1,s.back().gety())); // adds new block to the right of the snake
	    }else if(dir = 2){
			s.push(GameObject(s.back().getx(),s.back().gety()-1)); // adds new block to down side of the snake
		}else if(dir = 3){
			s.push(GameObject(s.back().getx(),s.back().gety()+1)); // adds new block to up side of the snake
		}
	return 1;
	}
	
	return 0;
}
	
void createFood(GameObject f){ // create food at a random new x and y position
	f.setx(rand()%480 + 1); 
	f.sety(rand()%320 + 1);
}
		
void drawScreen(queue <GameObject> s, GameObject f){
}
		
void handleInputs(){
}
		
void gameSetup(){
}
		
void gamePlay(){
}
		
void gameEnd(){
}

int main(void){
	queue <GameObject> snake;
	GameObject food(10,6);
	food.getx();
	return 1;
}
