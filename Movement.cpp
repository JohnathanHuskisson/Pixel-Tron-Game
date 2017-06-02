/*
Programmer     : Johnathan Huskisson
Program        : Movement.cpp
Description    : 
Last Edit      : 5-30-17    MM-DD-YY
*/

#include "Movement.h"
#include "Player.h"
#include <vector>



std::vector<Player> PlayerMovement(std::vector<Player> Players){

}

std::vector<Player> AIMovement(std::vector<Player>){
	
}

std::vector<Player> MovementSwitchStatement(std::vector<Player> Players ,Movement Move, int i){
	
	switch(Move){
	case MOVE_UP:
	    Players[i].Ypos--;
		break;
		
	case MOVE_DOWN:
		Players[i].Ypos++;
		break;
	
	case MOVE_RIGHT:
		Players[i].Xpos++;
		break;

	case MOVE_LEFT:
		Players[i].Xpos--;
		break;		
}
return Players; 
}

