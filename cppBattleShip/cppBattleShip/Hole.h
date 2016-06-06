#pragma once
class Hole
{
public:
	Hole();
	Hole(const Hole&);
	~Hole();

	Hole operator=(const Hole&);

	bool getFilled();
	void setFilled(bool);

	bool getFiredOn();
	void setFiredOn(bool);

private:
	bool filled;
	bool firedOn;
};

