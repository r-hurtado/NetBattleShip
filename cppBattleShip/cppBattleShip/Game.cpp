#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::placeShip(int x, char y, bool vertical, int ship, bool player1)
{
	(player1 ? p1 : p2).place(x, y, vertical, (player1 ? p1 : p2).getPieces()[ship]);
	(player1 ? p1 : p2).getPieces()[ship].setPlacement(x, y, vertical);
}

void Game::placeLoop(bool p)
{
	printf("\nInput string should be formatted like \"v,y,x\" where:");
	printf("\nv is whether the ship should be vertical: y for yes, n for no");
	printf("\ny is a character between a-j");
	printf("\nx is an integer between 1-10");
	printf("\nAll input should be lowercase with commas for seperating\n");

	bool valid;

	//loop for all ships
	//placeShip(2, 'd', false, 0, p);

	char input[7] = "";
	//input[0] = y/n verticalness
	//input[2] = y-value
	//input[4] = x-value (subtract 48)
	//input[6] = '\0'

	for (int i(0); i < 5; i++)
	{
		//Start validation do-while
		do{
			//Ask the user
			printf("\nPlease input placement for your ");
			printf((p ? p1 : p2).getPieces()[i].getShipName());
			printf(": ");

			//(re)set valid
			valid = true;

			//Input from user
			scanf_s("%6s", input, 7);

			//Validate user input
			//Example input string: "y,d,10"
			if (!(input[0] == 'y' || input[0] == 'n'))
			{
				printf("\nERROR: Input for v must be either y or n");
				valid = false;
			}

			else if (!(input[2] >= 97 && input[2] <= 106))
			{
				printf("\nERROR: Input for y must be between a-j");
				valid = false;
			}

			else if (!(input[4] >= 48 && input[4] <= 57))
			{
				printf("\nERROR: Input for x must be between 1-10");
				valid = false;
			}

			else if (input[4] >= 49 && !(input[5] == '0' || input[5] == '\0'))
			{
				printf("\nERROR: Input for x must be between 1-10");
				valid = false;
			}

			//Validate ship placement
			if (valid)
				valid = (p ? p1 : p2).checkPlacement((input[5] == '0' ? 10 : input[4] - 48), input[2], input[0] == 'y', (p ? p1 : p2).getPieces()[i]);

			if (!valid)
				printf("\nERROR: Invalid placement");

			//End validation do-while
		} while (!valid);

		//Place ship
		placeShip((input[5] == '0' ? 10 : input[4] - 48), input[2], input[0] == 'y', i, p);
	}
}

void Game::gameStart()
{
	p1.setOpponent(&p2);
	p2.setOpponent(&p1);

	placeLoop(true);
	placeLoop(false);
	//placeShip(1, 'b', false, 0, false);
	//placeShip(2, 'd', true, 1, false);

	//p1.printBoard();
	///*For Testing*/printf("\n----------------------------------\n");
	///*For Testing*/p2.printBoard();

	///*For Testing*/system("pause");

	////P1 firing on P2
	///*For Testing*/for (int i(3); i < 9; i++)
	//	/*For Testing*/	p1.fire(i + 1, 'h');

	////P2 firing on P1
	///*For Testing*/for (int i(3); i < 9; i++)
	//	/*For Testing*/	p2.fire(i + 1, 'g');

	//p1.printBoard();
	///*For Testing*/printf("\n----------------------------------\n");
	///*For Testing*/p2.printBoard();

	///*For Testing*/system("pause");

	bool first(true);
	while (!turn(first))
		first = !first;

	printf("\nCongratulations player ");
	printf((first ? "one" : "two"));
	printf(", you've won!\n");

	system("pause");
}

bool Game::turn(bool player1)
{
	(player1 ? p1 : p2).printBoard();

	printf("\nInput string should be formatted like \"yx\" where:");
	printf("\ny is a character between a-j");
	printf("\nx is an integer between 1-10");
	printf("\nAll input should be lowercase\n");

	bool valid;
	char input[4] = "";

	//Start validation do-while
	do{
		//Ask the user
		printf("\nPlease input firing coordinates: ");

		//(re)set valid
		valid = true;

		//Input from user
		scanf_s("%3s", input, 4);

		//Validate user input
		//Example input string: "d10"
		if (!(input[0] >= 97 && input[0] <= 106))
		{
			printf("\nERROR: Input for y must be between a-j");
			valid = false;
		}

		else if (!(input[1] >= 48 && input[1] <= 57))
		{
			printf("\nERROR: Input for x must be between 1-10");
			valid = false;
		}

		else if (input[1] >= 49 && !(input[2] == '0' || input[2] == '\0'))
		{
			printf("\nERROR: Input for x must be between 1-10");
			valid = false;
		}

		//End validation do-while
	} while (!valid);

	//Fire on valid coordinates
	printf((player1 ? p1 : p2).fire((input[2] == '0' ? 10 : input[1] - 48), input[0]) ? "Hit!\n" : "Miss...\n");

	//check for sunken ships
	checkSunk();
	/*for testing//for (int i(0); i < 5; i++)
		p1.getPieces()[i].setSunk(true);*/

	//check if player has won
	return (player1 ? p2 : p1).hasWon();
}

void Game::checkSunk()
{
	bool noneSunk(true);

	p1.checkSunk();
	printf("Player 1 sunken ships:");
	for (int i(0); i < 5; i++)
		if (p1.printSunk(i) != nullptr)
		{
			printf("\n  -");
			printf(p1.printSunk(i));
			noneSunk = false;
		}
	if (noneSunk)
		printf(" None yet");

	noneSunk = true;
	p2.checkSunk();
	printf("\nPlayer 2 sunken ships:");
	for (int i(0); i < 5; i++)
		if (p2.printSunk(i) != nullptr)
		{
			printf("\n  -");
			printf(p2.printSunk(i));
			noneSunk = false;
		}
	if (noneSunk)
		printf(" None yet");

	printf("\n");
}