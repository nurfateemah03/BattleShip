/*
 * Production.h
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdio.h>
#include <stdbool.h>
#include <string.h>//strncpy
#include <stdlib.h>//strtol
#include "Board.h"
#include "Battleship.h"
#include "Carrier.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"
#include "Tests.h"

#define FILENAMELENGTHALLOWANCE (50)



class Production {
public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);
	bool getYesNo(char* query);


private:

};

#endif /* PRODUCTION_H_ */
