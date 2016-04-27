#include "Board.h"

Board NewBoard()	//See Game.c -> NewGame()
{
	Board init;

	for (int i = 0; i < 5; i++)
	{
		init.Pieces[i] = NewShip();
	}

	init.Pieces[0] = SetShip(&init.Pieces[0], "Carrier", 5);
	init.Pieces[1] = SetShip(&init.Pieces[1], "Battleship", 4);
	init.Pieces[2] = SetShip(&init.Pieces[2], "Cruiser", 3);
	init.Pieces[3] = SetShip(&init.Pieces[3], "Submarine", 3);
	init.Pieces[4] = SetShip(&init.Pieces[4], "Destroyer", 2);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			init.Player[i][j] = NewHole();
			init.Enemy[i][j] = NewHole();
		}

	return init;
}

bool Fire(Board* opponent, int x, char y)
{
	return UnderFire(opponent, x, y);
}

/*Comment Block*/
bool UnderFire(Board* this, int x, char y)
{
	this->Player[x][y - 97].FiredOn = true;
	return this->Player[x][y - 97].Filled;
}

/*Comment Block*/
bool CheckOverlap(Board* this, int x, char y, bool vertical, Ship name)
{

}

/*Comment Block*/
bool HasWon(Board* this)
{

}

/*Comment Block*/
Board Place(Board* this, int x, char y, bool vertical, Ship ship)
{
	for (int i = 0; i < ship.Size; i++)
		if (vertical)
			this->Player[x + i][y - 97].Filled = true;
		else
			this->Player[x][y + i - 97].Filled = true;

	return *this;
}

/*Comment Block*/
void Print(Board* this)
{
	for (int i = 0; i < 10; i++)
		printf("  %d", i + 1);
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%c", i + 97);
		for (int j = 0; j < 10; j++)
		{
			printf("[");
			printf("%c", this->Enemy[i][j].FiredOn ? (this->Enemy[i][j].Filled ? 'H' : 'M') : ' ');
			printf("]");
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < 10; i++)
		printf("  %d", i + 1);
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%c", i + 97);
		for (int j = 0; j < 10; j++)
		{
			printf("[");
			printf("%c", this->Player[i][j].FiredOn ? (this->Player[i][j].Filled ? 'H' : 'M') : (this->Player[i][j].Filled ? 'F' : ' '));
			printf("]");
		}
		printf("\n");
	}
}

/*Comment Block*/
char* CheckSunk(Board* this)
{

}

void ClearShips(Board* this)
{
	for (int i = 0; i < 5; i++)
	{
		ClearShip(&this->Pieces[i]);
	}
}