/*
 * Board.h
 *
 *  Created on: Mar 3, 2022
 *      Author: theresesmith
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <stdio.h>
#include <stdlib.h>

#include "Carrier.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Submarine.h"
#include "Destroyer.h"

typedef struct
{
	bool hasBeenShot;
	bool partOfSunken;
	int row;
	int col;
	char symbol;
}Space;

typedef enum
{
	CARRIER,
	BATTLESHIP,
	CRUISER,
	SUBMARINE,
	DESTROYER
}ShipType;

class Board {
public:
	Board();
	virtual ~Board();
	void init();
	void welcomeScreen();
	void displayBoard();
	bool placeShip(ShipType s, int row, int col, int player, bool horizontal);
	bool place(Carrier*, int, int, int, bool);
	bool place(Battleship*, int, int, int, bool);
	bool place(Cruiser*, int, int, int, bool);
	bool place(Submarine*, int, int, int, bool);
	bool place(Destroyer*, int, int, int, bool);
	int  getRandomNumber (int lowest, int highest);
	int getSideLength();
private:
	int sideLength;
	Space** seasP;
	int players;
};

#endif /* BOARD_H_ */
