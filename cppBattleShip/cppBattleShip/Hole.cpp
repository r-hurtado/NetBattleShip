#include "Hole.h"

Hole::Hole() :filled(false), firedOn(false)
{
}

Hole::Hole(const Hole& H): filled(H.filled), firedOn(H.firedOn)
{
	//*this = H;
}

Hole::~Hole()
{
	filled = false;
	firedOn = false;
}

Hole Hole::operator=(const Hole& H)
{
	if (this != &H)
	{
		filled = H.filled;
		firedOn = H.firedOn;
	}
	return *this;
}

bool Hole::getFilled(){
	return filled;
}

void Hole::setFilled(bool Filled){
	filled = Filled;
}

bool Hole::getFiredOn(){
	return firedOn;
}

void Hole::setFiredOn(bool FiredOn){
	firedOn = FiredOn;
}