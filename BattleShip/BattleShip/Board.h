#ifndef BOARD_H
#define BOARD_H
#include <stdlib.h>
#include "Hole.h"
#include "Ship.h"

typedef struct Board{
	Ship Pieces[5];
	Hole Player[10][10];
	Hole Enemy[10][10];
	//struct Board* Opponent;
}Board;

Board NewBoard();

bool Fire(Board*, int, char);
bool UnderFire(Board*, int, char);
bool CheckOverlap(Board*, int, char, bool, Ship);
bool HasWon(Board*);
Board Place(Board*, int, char, bool, Ship);
void Print(Board*);
char* CheckSunk(Board*);
void ClearShips(Board*);

#endif