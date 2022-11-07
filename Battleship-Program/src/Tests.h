/*
 * Tests.h
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <stdio.h>
#include "Production.h"



class Tests {
public:
	Tests();//constructor
	virtual ~Tests();
	bool tests();
	bool  testWhoGoesFirst();
	bool  testCreateSeas();
	bool testDisplaySeasInConsole();
	bool testCreateFleets();
	bool testGetYesNo(); //place owh fleet
	bool  testPlaceShip();// same for placing ships and shooting ships
	bool  testLostHull();
	bool  testLostGame();
	bool  testAnnounceWinner();

private:

};
#endif /* TESTS_H_ */
