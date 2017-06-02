#ifndef GUARD_PLAYER
#define GUARD_PLAYER

#include <vector>

struct Player{
	int Xpos;
	int Ypos;
	int Color; 
	int LastX;
	int LastY;
	bool Elimited; 
	int Target; 
	 	
};

std::vector<Player> CheckEliminate(std::vector<Player> Players, int totalplayers);

bool CheckVictory(std::vector<Player> Players, int totalplayers);

std::vector<Player> CreatePlayers(std::vector<Player> Players, int totalplayers);

#endif
