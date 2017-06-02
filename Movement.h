#ifndef GUARD_MOVEMENT
#define GUARD_MOVEMENT

#include <vector>
#include "Player.h"
enum Movement{
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT
};


std::vector<Player> PlayerMovement(std::vector<Player> Players);

std::vector<Player> AIMovement(std::vector<Player> Players);

std::vector<Player> MovementSwitchStatement(std::vector<Player> Players,Movement Move, int i);

#endif
