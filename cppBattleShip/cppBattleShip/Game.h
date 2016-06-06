#pragma once
#include "Board.h"

class Game
{
public:
	Game();
	~Game();

	void gameStart();
	void placeLoop(bool);
	void placeShip(int, char, bool, int, bool);
	void checkSunk();
	bool turn(bool);

private:
	Board p1;
	Board p2;
};

