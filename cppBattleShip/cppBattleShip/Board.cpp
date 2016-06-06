#include "Board.h"

Board::Board() : opponent(nullptr)
{
	pieces[0].ShipInit("Carrier", 5);
	pieces[1].ShipInit("Battleship", 4);
	pieces[2].ShipInit("Cruiser", 3);
	pieces[3].ShipInit("Submarine", 3);
	pieces[4].ShipInit("Destroyer", 2);
}

Board::Board(const Board& B) :opponent(B.opponent)
{
	for (int i(0); i < 5; i++)
		pieces[i] = B.pieces[i];

	for (int i(0); i < 10; i++)
		for (int j(0); j < 10; j++)
			player[i][j] = B.player[i][j];

	for (int i(0); i < 10; i++)
		for (int j(0); j < 10; j++)
			enemy[i][j] = B.enemy[i][j];
}

Board::~Board()
{
	opponent = nullptr;
}

Board Board::operator=(const Board& B)
{
	if (this != &B)
	{
		for (int i(0); i < 5; i++)
			pieces[i] = B.pieces[i];

		for (int i(0); i < 10; i++)
			for (int j(0); j < 10; j++)
				player[i][j] = B.player[i][j];

		for (int i(0); i < 10; i++)
			for (int j(0); j < 10; j++)
				enemy[i][j] = B.enemy[i][j];
		opponent = B.opponent;
	}
	return *this;
}

bool Board::fire(int x, char y)
{
	enemy[y - 97][x - 1].setFiredOn(true);
	//enemy[y - 97][x - 1].getFilled();
	return opponent->underFire(x, y);
}

bool Board::underFire(int x, char y)
{
	player[y - 97][x - 1].setFiredOn(true);
	return player[y - 97][x - 1].getFilled();
}

bool Board::hasWon()
{
	bool won(true);

	for (int i(0); i < 5; i++)
	{
		if (!pieces[i].getSunk())
			won = false;
	}
	return won;
}

void Board::checkSunk()
{
	bool sunk(true);
	char y;
	int x;

	for (int i(0); i < 5; i++)
	{
		sunk = true;
		if (!pieces[i].getSunk())
		{
			y = pieces[i].getY();
			x = pieces[i].getX();
			for (int j(0); j < pieces[i].getSize(); j++)
				if (pieces[i].getVertical())
				{
					if (!player[y + j - 97][x - 1].getFiredOn())
						sunk = false;
				}
				else
					if (!player[y - 97][x + j - 1].getFiredOn())
						sunk = false;
			pieces[i].setSunk(sunk);
		}
	}
}

char* Board::printSunk(int i)
{
	return pieces[i].getSunk() ? pieces[i].getShipName() : nullptr;
}

void Board::printBoard()
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
			printf("%c", enemy[i][j].getFiredOn() ? (enemy[i][j].getFilled() ? 'H' : 'M') : ' ');
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
			printf("%c", this->player[i][j].getFiredOn() ? (this->player[i][j].getFilled() ? 'H' : 'M') : (this->player[i][j].getFilled() ? 'F' : ' '));
			printf("]");
		}
		printf("\n");
	}
}

bool Board::checkPlacement(int x, char y, bool vertical, Ship ship)
{
	bool valid(true);

	for (int i = 0; i < ship.getSize(); i++)
		if (vertical)
		{
			if (y + i - 97 > 9 || player[y + i - 97][x - 1].getFilled())
				valid = false;
		}
		else
		{
			if (x + i - 1 > 9 || player[y - 97][x + i - 1].getFilled())
				valid = false;
		}

	return valid;
}

void Board::place(int x, char y, bool vertical, Ship& ship)
{
	for (int i = 0; i < ship.getSize(); i++)
		if (vertical)
		{
			player[y + i - 97][x - 1].setFilled(true);
			opponent->ePlace(x, y + i);
		}
		else
		{
			player[y - 97][x + i - 1].setFilled(true);
			opponent->ePlace(x + i, y);
		}
	ship.setPlacement(x, y, vertical);
}

void Board::ePlace(int x, char y)
{
	enemy[y - 97][x - 1].setFilled(true);
}

Ship* Board::getPieces()
{
	return pieces;
}

void Board::setOpponent(Board* B)
{
	opponent = B;
}

Board Board::getOpponent()
{
	return *opponent;
}