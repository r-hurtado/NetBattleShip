#pragma once
#include <iostream>
class Ship
{
public:
	Ship();
	void ShipInit(char*, int);
	Ship(const Ship&);
	~Ship();

	Ship operator=(const Ship&);

	char* getShipName();
	void setShipName(char*);

	bool getVertical();
	void setVertical(bool);

	bool getSunk();
	void setSunk(bool);

	int getSize();
	void setSize(int);

	int getX();
	void setX(int);

	char getY();
	void setY(char);

	void setPlacement(int, char, bool);

private:
	char* shipName;
	bool vertical, sunk;
	int size, x;
	char y;
};

