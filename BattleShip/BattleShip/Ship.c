#include "Ship.h"

Ship NewShip()
{
	Ship init;

	//init.ShipName = Unknown at compile time
	//init.Size = Unknown at compile time
	init.Sunk = false;
	init.Vertical = false;
	init.X = 0;
	init.Y = 'Y';

	return init;
}

Ship SetShip(Ship* this, char* name, int size)
{
	int len = 0;
	while (name[len++] != '\0');

	this->ShipName = (char*)malloc(len);
	for (int i = 0; i < len; i++)
	{
		this->ShipName[i] = name[i];
	}

	this->Size = size;

	return *this;
}

void ClearShip(Ship* this)
{
	free(this->ShipName);
}