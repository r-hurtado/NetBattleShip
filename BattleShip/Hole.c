#include "Hole.h"

Hole NewHole()
{
	Hole init;

	init.Filled = false;
	init.FiredOn = false;

	return init;
}