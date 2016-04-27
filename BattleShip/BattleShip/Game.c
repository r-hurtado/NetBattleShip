#include "Game.h"

Game NewGame()
{
	Game init;

	init.P1 = NewBoard();
	init.P2 = NewBoard();



	return init;
}

void StartGame(Game* this)
{
	this->P2 = Place(&this->P2, 1, 'b', false, this->P2.Pieces[0]);
	this->P2 = Place(&this->P2, 2, 'c', true, this->P2.Pieces[1]);

	Print(&this->P1);
	printf("\n----------------------------------\n");
	Print(&this->P2);

	system("pause");

	//P1 firing on P2
	this->P1.Enemy[1]['b' - 97].Filled = Fire(&this->P2, 1, 'b');
	this->P1.Enemy[1]['b' - 97].FiredOn = true;

	Print(&this->P1);
	printf("\n----------------------------------\n");
	Print(&this->P2);

	system("pause");

	ClearShips(&this->P1);
	ClearShips(&this->P2);

	system("pause");
}