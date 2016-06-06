#include "Ship.h"

Ship::Ship() :shipName(nullptr), vertical(false), sunk(false), size(0), x(0), y('A')
{
}

void Ship::ShipInit(char* S, int Size)
{
	//delete[] shipName;
	shipName = new char[strlen(S) + 1];
	strcpy_s(shipName, strlen(shipName), S);
	size = Size;
}

Ship::Ship(const Ship& S) :vertical(S.vertical), sunk(S.sunk), x(S.x), y(S.y)
{
	//*this = S;
	ShipInit(S.shipName, S.size);
}

Ship::~Ship()
{
	//delete[] shipName;
	shipName = nullptr;
}


Ship Ship::operator=(const Ship& S)
{
	if (this != &S)
	{
		if (shipName == nullptr)
			shipName = new char[strlen(S.shipName) + 1];
		else if (strlen(S.shipName) != strlen(shipName))
		{
			delete[] shipName;
			shipName = new char[strlen(S.shipName) + 1];
		}

		strcpy_s(shipName, strlen(shipName), S.shipName);
		vertical = S.vertical;
		sunk = S.sunk;
		size = S.size;
		x = S.x;
		y = S.y;
	}
	return *this;
}

char* Ship::getShipName()
{
	return shipName;
}


void Ship::setShipName(char* ShipName)
{
	if (strlen(ShipName) != strlen(shipName))
	{
		delete[] shipName;
		shipName = new char[strlen(ShipName) + 1];
	}

	strcpy_s(shipName, strlen(shipName), ShipName);
}

bool Ship::getVertical()
{
	return vertical;
}

void Ship::setVertical(bool Vertical)
{
	vertical = Vertical;
}

bool Ship::getSunk()
{
	return sunk;
}

void Ship::setSunk(bool Sunk)
{
	sunk = Sunk;
}

int Ship::getSize()
{
	return size;
}

void Ship::setSize(int Size)
{
	size = Size;
}

int Ship::getX()
{
	return x;
}

void Ship::setX(int X)
{
	x = X;
}

char Ship::getY()
{
	return y;
}

void Ship::setY(char Y)
{
	y = Y;
}

void Ship::setPlacement(int x, char y, bool vertical)
{
	setX(x);
	setY(y);
	setVertical(vertical);
}