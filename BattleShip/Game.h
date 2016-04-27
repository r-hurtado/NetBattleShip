#ifndef GAME_H
#define GAME_H
#include "Board.h"

typedef struct{
	Board P1;
	Board P2;
}Game;

Game NewGame();
void StartGame(Game*);

#endif