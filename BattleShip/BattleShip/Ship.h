#ifndef SHIP_H
#define SHIP_H
#include "Bool.h"

typedef struct{
	char* ShipName;
	bool Vertical;
	bool Sunk;
	int Size;
	int X;
	char Y;
}Ship;

Ship NewShip(); 
Ship SetShip(Ship*, char*, int);
void ClearShip(Ship*);

#endif