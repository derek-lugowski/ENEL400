// SnakeGame.cpp

#include "SnakeGame.h"
//#include "GameObject.h"
#include <deque>
#include <stdlib.h>\
//#include <controler.h>
//#include <Arduino.h>

using std::deque;

int score;

GameObject moveSnake(int newdir, deque <GameObject> s){
	GameObject tempback; // creates a temporary object to store the data from the back of the snake so that it can be removed from screen
	if(newdir = 0){
		s.push_front(GameObject(s.front().getx() - 1,s.front().gety())); // adds new block to the left of the snake
		tempback = s.back();
		s.pop_back(); //removes last block
	}else if(newdir = 1){
		s.push_front(GameObject(s.front().getx() + 1,s.front().gety())); // adds new block to the right of the snake
		tempback = s.back();
		s.pop_back();
	}else if(newdir = 2){
		s.push_front(GameObject(s.front().getx(),s.front().gety()-1)); // adds new block to down side of the snake
		tempback = s.back();
		s.pop_back();
	}else if(newdir = 3){
		s.push_front(GameObject(s.front().getx(),s.front().gety()+1)); // adds new block to up side of the snake
		tempback = s.back();
		s.pop_back();
	}else{
		tempback = GameObject(-1,-1); // creates a random object offscreen;
	}
	return tempback;
}
	
int collisionSelf(deque <GameObject> s){
	deque<GameObject>::iterator it = s.begin();// creates an iterator(pointer) pointing to the head of the snake 
	do{ // while it is not eqaul to the tail of the snake
		if(it->getx() == s.front().getx() && it->gety() == s.front().gety()){// compares whether the element it is pointing to is in the same position as snake head
			return 1;
		}
		it++; // points to the next element in snake body
	}while(it != s.end());
	return 0;
}

int collisionWall(deque <GameObject> s){
	if( s.front().getx() == 0 || s.front().getx() == 48 || s.front().gety() == 0 || s.front().gety() == 32){
			return 1;
	}else{
		return 0;
	}
}
	
void eating(deque <GameObject> s, GameObject f, int dir){
	if(s.back().getx() == f.getx() && s.back().gety() == f.gety()){//checks to see if head is in the same place as food
		score += 10;
		if(dir = 0){
			s.push_front(GameObject(s.front().getx() - 1,s.front().gety())); // adds new block to the left of the snake
		}else if(dir = 1){
			s.push_front(GameObject(s.front().getx() + 1,s.front().gety())); // adds new block to the right of the snake
		}else if(dir = 2){
			s.push_front(GameObject(s.front().getx(),s.front().gety()-1)); // adds new block to down side of the snake
		}else if(dir = 3){
			s.push_front(GameObject(s.front().getx(),s.front().gety()+1)); // adds new block to up side of the snake
		}
	createFood(f);
	}
}
	
void createFood(GameObject f){ // create food at a random new x and y position
	f.setx(rand()%480 + 1); 
	f.sety(rand()%320 + 1);
}
		
void drawScreen(deque <GameObject> s, GameObject f/*,MCUFRIEND_kbv tft*/){
	//needs commands to draw screen layout and snake and food
	//draw score 
	s.front().draw(2390); //draws intial snake (1 rectangle) put in a random colour so please change also add screen
	f.draw(789); //put in a random colour so please change also add screen as a variable 
}

void updateScreen(deque <GameObject> s, GameObject f, GameObject tail/*,MCUFRIEND_kbv tft*/){
	//draws new elements of snake and updates food location 
	//for food check whether location changed and then draw
	//update score
	s.front().draw(329408);//draws new head of snake put in a random colour so please change also add screen
	int x = tail.getx(); // use the following parameters to draw screen colour over where the last block of the snake was
	int y = tail.gety();
	int width = tail.getwidth();
	int height = tail.getheight();
}
		
int handleInputs(){
	//check if buttons are pressed and then return direction 0: left, 1: right, 2: down, 3: up
}
		
void gameSetup(deque <GameObject> s, GameObject f){
	drawScreen(s,f);
	score = 0;
}
		
void gamePlay(deque <GameObject> s, GameObject f){
	int direction = handleInputs();
	GameObject removedBlock = moveSnake(direction,s);
	if(collisionSelf(s) || collisionWall(s)){
		gameEnd();
	}
	eating(s,f,direction);
	updateScreen(s,f, removedBlock);
}
		
void gameEnd(){
	//exits game loop and goes back to menu, maybe show you lose and final score?? 
}

int main(void){
	deque <GameObject> snake;
	GameObject food(10,6);
	food.getx();
	return 1;
}
