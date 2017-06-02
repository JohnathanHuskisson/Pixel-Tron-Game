/*
Programmer     : Johnathan Huskisson
Program        : Player.cpp
Description    : 
Last Edit      : 5-30-17    MM-DD-YY
*/
#include <graphics.h>
#include <vector>
#include "Player.h"
#include <math.h>
#include <time.h>

std::vector<Player> CheckEliminate(std::vector<Player> Players, int totalplayers){
//	printf("CHECK ELIM \n");
	for(int i  = 0; i < totalplayers; i++){
		if(Players[i].Elimited != true)
		{
			int j = 0;
			while(Players[i].Elimited != true && j < totalplayers){
			
			if(getpixel(Players[i].Xpos,Players[i].Ypos) != BLACK||  
			((Players[i].Xpos == Players[i].LastX) && (Players[i].Ypos == Players[i].LastY))||
			(Players[i].Xpos == Players[j].Xpos && Players[i].Ypos == Players[j].Ypos && j != i)){
				Players[i].Elimited = true;
			}
			j++;
		}
			
		}
		
	}
	
	return Players; 
}

bool CheckVictory(std::vector<Player> Players, int totalplayers){
int elimitated = 0; 
//	printf("CHECK VICTORY \n");
for(int i = 0; i < totalplayers; i++){
	if(Players[i].Elimited  == true){
		elimitated++;
	}
}
if(totalplayers - elimitated <= 1){
	for(int i = 0 ;i < totalplayers; i++){
		if(Players[i].Elimited != true){
			 printf("Player %d Wins \n", i);
			 return true; 
		}
	}
	printf("There is a Draw \n");
	return true;
}
	return false; 
}

std::vector<Player> CreatePlayers(std::vector<Player> Players, int totalplayers){
	//	printf("CREATE PLAYERS \n");
	srand(time(NULL));
	 for(int i = 0; i < totalplayers; i++){

  Player Tagonist;
  //there are 2pi radians in every circle
  // given the origin and the last position get the current position angle in degrees 
if(i <= 50){

  Tagonist.Xpos = 200*cos(((double)i/totalplayers)* 360) + 220;
  Tagonist.Ypos = 200*sin(((double)i/totalplayers) * 360) +220;
}
if(i >50 && i < 100){
	Tagonist.Xpos = 100 *cos(((double)i/totalplayers)* 360) + 220;
	Tagonist.Ypos = 100 *sin(((double) i/totalplayers) * 360) + 220;
	
}
if(i >= 101){
	Tagonist.Xpos = rand() % 596 + 3;
	Tagonist.Ypos = rand() % 447 + 3; 
}
  if(i%getmaxcolor() != BLACK){
	Tagonist.Color = i% getmaxcolor();
  }
  else{
  Tagonist.Color = i % getmaxcolor() + 1;
  }
  Tagonist.Elimited = false;
	Tagonist.Target = rand() % totalplayers; 
	
  Players.push_back(Tagonist);
}

return Players; 

}
