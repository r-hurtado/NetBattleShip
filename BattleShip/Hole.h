#ifndef HOLE_H
#define HOLE_H
#include "Bool.h"

typedef struct{
	bool Filled;
	bool FiredOn;
}Hole;

Hole NewHole();

#endif