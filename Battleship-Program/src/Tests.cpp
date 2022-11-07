/*
 * Tests.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#include "Tests.h"

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}
bool Tests::tests() {
	bool answer = true;
	// This will invoke the other tests
	bool ok1 = testWhoGoesFirst();
	bool ok2 = testCreateSeas();
	bool ok5 = testCreateFleets();
	bool ok3 = testGetYesNo();
	bool ok4 = testPlaceShip();
	bool ok6 = testLostHull();
	bool ok7 = testLostGame();
	bool ok8 = testAnnounceWinner();
	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8;
	if (ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8){
			puts("All tests passed");

		}
		else{
			puts("Some tests failed");
		}
	return answer;
}

bool  Tests::testWhoGoesFirst(){
	return false;
}
bool  Tests::testCreateSeas(){
	return false;
}
bool  Tests::testDisplaySeasInConsole(){
	return false;
}
bool  Tests::testCreateFleets(){
	return false;
}
bool  Tests::testGetYesNo(){
	bool ok = true;
	puts("starting testgetYesNo"); fflush(stdout);

	//setup
	Production* pP = new Production();
	char* query1 = "Type y";
	char* query2 = "Type n";
	bool rightAnswer = true;

	//trial
	bool answer = pP->getYesNo(query1);
	bool ok1 = (answer == rightAnswer);
	answer = pP->getYesNo(query2);
	rightAnswer = false;
	bool ok2 = (answer == rightAnswer);
	ok = ok1 && ok2;
	//render judgment
	if(ok)
	{
		puts("getYesNo passed its test");
	}
	else
	{
		puts("getYesNo did not pass its test");
	}
	return ok;
}
bool  Tests::testPlaceShip(){
	bool ok = true;

	puts("starting testPlaceShip"); fflush(stdout);

	//setup
	Board* board = new Board();

	int sideLength = 10;
	int row = 3;
	int col = 1;
	int player = 0;
	int numOfPlayers = 1;
	bool horizontal = true;
	board->init();
	Space** seasP = (Space**) malloc(numOfPlayers*sideLength*sideLength*sizeof(Space*));
	Carrier* carrier = new Carrier();
	bool worked = true;

	bool answer = board->place(carrier, row, col, player, true);


	for(int i = 0; i < carrier->getLength(); i++)
	{
		Space** where = seasP+(sideLength*sideLength*player)+(row*sideLength)+col;
		Space* x = *where;
		bool ok = x->symbol=='~';
		if(!ok)
		{
			worked = false;
		}
		if(horizontal)
		{
			col++;
		}
		else
		{
			row++;
		}
	}
	if(worked)
	{
		int r = row;
		int cl = col;
		//first check
		for(int i = 0; i< carrier->getLength(); i++)
		{
			Space** where = seasP+(sideLength*sideLength*player)+(r*sideLength)+cl;
			Space* x = *where;
			x->symbol='C';
			if(horizontal)
			{
				cl++;
			}
			else
			{
				r++;
			}
		}
	}
	ok = answer &&worked;
	if(ok)
		{
			puts("testPlaceShip passed its test");
		}
		else
		{
			puts("testPlaceShip did not pass its test");
		}
		return ok;

}
bool  Tests::testLostHull(){
	return false;
}
bool  Tests::testLostGame(){
	return false;
}
bool  Tests::testAnnounceWinner(){
	return false;
}

