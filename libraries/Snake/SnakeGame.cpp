// SnakeGame.cpp

#include "SnakeGame.h"
//#include "GameObject.h"
#include <deque>
#include <stdlib.h>\
#include <controler.h>
#include <Arduino.h>

using std::deque;

int score;

void moveSnake(int newdir, deque <GameObject> s){
	if(newdir = 0){
		s.push_front(GameObject(s.front().getx() - 1,s.front().gety())); // adds new block to the left of the snake
		s.pop_back(); //removes last block
	}else if(newdir = 1){
		s.push_front(GameObject(s.front().getx() + 1,s.front().gety())); // adds new block to the right of the snake
		s.pop_back();
	}else if(newdir = 2){
		s.push_front(GameObject(s.front().getx(),s.front().gety()-1)); // adds new block to down side of the snake
		s.pop_back();
	}else if(newdir = 3){
		s.push_front(GameObject(s.front().getx(),s.front().gety()+1)); // adds new block to up side of the snake
		s.pop_back();
	}//need an else??
}
	
int collisionSelf(deque <GameObject> s){
	deque<GameObject>::iterator it = s.begin();// creates an iterator(pointer) pointing to the head of the snake 
	do{ // while it is not eqaul to the tail of the snake
		if(it->getx() == s.front().getx() && it->gety() == s.front().gety()){// compares whether the element it is pointing to is in the same position as snake head
			return 1;
		}
		it++; // points to the next element in snake body
	}while((it != s.end());
	return 0;
}

int collisionWall(deque <GameObject> s){
	if( s.front().getx() == 0 || s.front().getx() == 48 || s.front().gety() == 0 || s.front().gety() == 32){
			return 1;
	}else{
		return 0;
	}
}
	
int eating(deque <GameObject> s, GameObject f, int dir){
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
	return 1;
	}
	
	return 0;
}
	
void createFood(GameObject f){ // create food at a random new x and y position
	f.setx(rand()%480 + 1); 
	f.sety(rand()%320 + 1);
}
		
void drawScreen(deque <GameObject> s, GameObject f){
}
		
int handleInputs(){
}
		
void gameSetup(deque <GameObject> s, GameObject f){
	drawScreen();
	
}
		
void gamePlay(deque <GameObject> s, GameObject f){
}
		
void gameEnd(deque <GameObject> s, GameObject f){
}

int main(void){
	deque <GameObject> snake;
	GameObject food(10,6);
	food.getx();
	return 1;
}
