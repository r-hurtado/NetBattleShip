#pragma once
#include "Ship.h"
#include "Hole.h"

class Board
{
public:
	Board();
	Board(const Board&);
	~Board();
	Board operator=(const Board&);

	bool fire(int, char);
	bool underFire(int, char);
	bool hasWon();
	void checkSunk();
	char* printSunk(int);
	void printBoard();
	bool checkPlacement(int, char, bool, Ship);
	void place(int, char, bool, Ship&);
	void ePlace(int, char);

	Ship* getPieces();
	void setOpponent(Board*);
	Board getOpponent();

private:
	Ship pieces[5];
	Hole player[10][10];
	Hole enemy[10][10];
	Board* opponent;
};

