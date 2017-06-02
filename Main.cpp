/*
Programmer     : Johnathan Huskisson
Program        : Main.cpp
Description    : Builds the game 
Last Edit      : 5-30-17
*/
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <math.h>

#include "Movement.h"
#include "Player.h"

using std::vector;

  
char getInput(char *c)
{
    if (kbhit())
    {
         *c = getch();
         return *c; 
    }
	return ' '; // No keys were pressed so default to a spacebar press
}

int main(){
	
int totalplayers;
int i, gd = DETECT,gw;

/* for(int i = 0; i < totalplayers; i++)
 {
 	std::cout << Players[i].Xpos << " "
 		 << Players[i].Ypos << " "
 		 << Players[i].Color << " "
 		 << Players[i].Elimited << " "
 		 << Players[i].Target << "     "
 		 << std::endl ;
 }*/

bool victory = false; 
	Movement Move = MOVE_LEFT;
	char key = ' '; 
	char * driver ; 

std::string input; 
std::cout <<"How many players?(2-100)";
std::cin >> input;
while(isdigit((int)input.c_str()) != true && (atoi(input.c_str() )< 2 || atoi(input.c_str()) > 100) ){
	std::cout << "Try again" << std::endl;
	std::cin >> input; 
}
totalplayers = atoi(input.c_str()); 
std::cout << "Players: "<< totalplayers; 

initgraph(&gd,&gw,driver);
setcolor(YELLOW);
line(600,1,600,450);
line(600,1,2,1);
line(2,450,600,450);
line(2,1,2,450);


 vector<Player> Players;

 Players = CreatePlayers(Players, totalplayers);
 std::cout << std::endl; 
while(victory != true){

for(int i = 0; i < totalplayers; i++){
	putpixel(Players[i].Xpos,Players[i].Ypos,Players[i].Color);
	Players[i].LastX = Players[i].Xpos;
	Players[i].LastY = Players[i].Ypos; 
}

//start player movement

if(Players[0].Elimited != true)
		{
		//putting the getch() function like this makes 
		//it so it doesn't require user input for the AI to move
		//
		//
		//in other words the game keeps functioning without user input. 
		char ch = getInput(&key);


	switch(ch){
	case 'w':
		Move = MOVE_UP;

		break;
	case 's':
		Move = MOVE_DOWN;

		break;
	case 'd':
		Move = MOVE_RIGHT;

		break;
	case 'a':
		Move = MOVE_LEFT;
	
		break;
	default:
		break;
		//nothing
}

Players = MovementSwitchStatement(Players,Move,0);

//	std::cout << Players[0].Xpos << " "
 //		 << Players[0].Ypos << " "
 //		 << Players[0].Color << " "
 //		 << Players[0].Elimited << "   "
 //		 << true << " " << false 
 //		 << std::endl ;
//
//
//end of player movement
}

//start AI movement

//i is supposed to be initialized to 1 because 0 is the user-player but 
// I put it to zero so I wouldn't have to play so the games go faster

for(int i = 1; i < totalplayers; i++){

if(Players[i].Elimited != true){
	
vector<vector<int> > graph(3,vector<int>(3,-4));
for(int p = 0; p < 3; p++){
	for(int j = 0; j < 3; j++){
		int pixColor = getpixel((Players[i].Xpos -1 + j),(Players[i].Ypos - 1 + p));
		if(pixColor != 0){
		graph[p][j] = pixColor; 
		}
	}
 
}

int a = 1,b = 1,d = Players[i].Target, loop = 0;

a = rand() % 10;
b = rand() % 3;
while(Players[d].Elimited == true){
	int closeist;
	double currentdist;
	double dist = 3600;
for( int t = 0; t < Players.size(); t++){
	currentdist = sqrt(pow(abs(Players[i].Ypos - Players[t].Ypos),2) + pow(abs(Players[t].Xpos - Players[i].Xpos),2));
	if(currentdist < dist && Players[t].Elimited != true){
		dist = currentdist; 
		closeist = t; 
	}
}
d = closeist; 
}


Movement aiMove = MOVE_UP;

	bool movement = false;
	int c = Players[i].Ypos - Players[d].Ypos + b - a;
	int z = Players[i].Xpos - Players[d].Xpos + a - b;
	int left = graph[0][0] * graph[2][0],
	right = graph[2][0] * graph[2][2],
	top = graph[0][0] * graph[2][0],
	bottom = graph[0][2] * graph[2][2];
	if( graph[2][1] <=0 && abs(c) <= abs(z) &&  c < 0){
		aiMove = MOVE_DOWN;
		movement = true;
	}
	
	if( graph[0][1] <= 0  && abs(c) > abs(z) &&  c > 0 &&movement == false){
		aiMove = MOVE_UP;
		movement = true;
	}

	if(graph[1][2] <= 0  && abs(z) >= abs(c) && z < 0  && movement == false){
		aiMove = MOVE_RIGHT;
		movement = true;
	}
	
	if(graph[1][0] <= 0  &&  abs(z) > abs(c) && z > 0 && movement == false) {
		aiMove = MOVE_LEFT;
		movement = true;
	}
	
	if( graph[1][2] <= 0  &&  right == 0 && movement == false){
	aiMove = MOVE_RIGHT;
	movement = true;
	}
	
	if( graph[1][0] <= 0 && left == 0 && movement == false) {
		aiMove = MOVE_LEFT;
		movement = true;
	}
	
	if(graph[2][1] <= 0 &&  bottom == 0 && movement == false){
		aiMove = MOVE_DOWN;
		movement = true;
	}
	if(graph[0][1] <= 0 &&  top == 0 && movement == false){
		aiMove = MOVE_UP;
		movement = true;
	}
	if( graph[1][2] <= 0  && movement == false){
	aiMove = MOVE_RIGHT;
	movement = true;
	}
	
	if( graph[1][0] <= 0 && movement == false) {
		aiMove = MOVE_LEFT;
		movement = true;
	}
	
	if(graph[2][1] <= 0  && movement == false){
		aiMove = MOVE_DOWN;
		movement = true;
	}
	if(graph[0][1] <= 0 && movement == false){
		aiMove = MOVE_UP;
		movement = true;
	}

Players = MovementSwitchStatement(Players,aiMove,i);

 /*std::cout << std::endl << std::endl;  
 	std::cout << Players[i].Xpos << " "
 		 << Players[i].Ypos << " "
 		 << Players[i].Color << " "
 		 << Players[i].Elimited << "   "
 		 << true << " " << false 
 		 << std::endl ;
 */		 
graph.clear();
}

}
//end AI movement 

Players = CheckEliminate(Players,totalplayers);

/*std::cout << std::endl << std::endl; 
for(int i = 0; i < totalplayers; i++)
 {
  std::cout << std::endl << std::endl;  
 	std::cout << Players[i].Xpos << " "
 		 << Players[i].Ypos << " "
 		 << Players[i].Color << " "
 		 << Players[i].Elimited << "   "
 		 << true << " " << false 
 		 << std::endl ;
 }*/
 

// this delay is for the user-player

if(Players[0].Elimited != true){
delay(20);

}
else{
//this is when the user-player dies it speeds up the game. 
delay(1);
}
victory = CheckVictory(Players,totalplayers);
}

for(int x = 3; x < 600; x++){
	for(int y = 2; y < 450; y++){
		putpixel(x,y,BLACK);
	}
}
 

return 0;
}

