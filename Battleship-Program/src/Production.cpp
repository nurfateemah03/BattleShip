/*
 * Production.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: theresesmith
 */

#include "Production.h"

Production::Production() {
	// TODO Auto-generated constructor stub

}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::prod(int argc, char* argv[])
{
	bool answer = true;
	bool whoGoesFirst = true;

	if(argc <=1) //no interesting information
	{
		puts("Usage: Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d interesting arguments.\n", argc-1);
		fflush(stdout);


		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string
			//in this program our arguments are NR, NC, gens, filename, print and pause
			//because pause is optional, argc could be 6 or 7
			//because print is optional (if print is not present, neither is pause) argc could be 5
			switch(i)
			{
			case 1:
				//this is

				if(strlen(argv[i])>=2)
				{
					puts("string is too long.");
					fflush(stdout);
					answer = false;
				}
				else
				{
					whoGoesFirst = (bool)strtol(argv[i], NULL, 10);
					printf("result of who goes first was was %d.\n", whoGoesFirst);
					fflush(stdout);
				}
				break;


			default:
				puts("Unexpected argument count."); fflush(stdout);
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count
		puts("after reading arguments"); fflush(stdout);
	}//end of there is interesting information

	//Setup the game
	Board* theBoard = new Board();
	theBoard->init();
	theBoard->welcomeScreen();
	theBoard->displayBoard();//all water

	//Get the user's preference for where they go, or else put them in a random spot
	int row;
	int col;
	row = theBoard->getRandomNumber(0, theBoard->getSideLength());
	col = theBoard->getRandomNumber(0, theBoard->getSideLength()-5);

	bool worked = theBoard->placeShip(CARRIER, row,col,0,true);
	if(!worked)
	{
		puts("Placement of carrier didn't work.");
	}


	row = theBoard->getRandomNumber(0, theBoard->getSideLength());
	col = theBoard->getRandomNumber(0, theBoard->getSideLength()-4);
	worked = theBoard->placeShip(BATTLESHIP, row, col,0,true);
	if(!worked)
	{
		puts("Placement of battleship didn't work.");
	}

	row = theBoard->getRandomNumber(0, theBoard->getSideLength());
	col = theBoard->getRandomNumber(0, theBoard->getSideLength()-3);
	worked = theBoard->placeShip(CRUISER, row,col,0,true);
	if(!worked)
	{
		puts("Placement of cruiser didn't work.");
	}

	row = theBoard->getRandomNumber(0, theBoard->getSideLength());
	col = theBoard->getRandomNumber(0, theBoard->getSideLength()-3);
	worked = theBoard->placeShip(SUBMARINE, row, col,0,true);
	if(!worked)
	{
		puts("Placement of submarine didn't work.");
	}

	row = theBoard->getRandomNumber(0, theBoard->getSideLength());
	col = theBoard->getRandomNumber(0, theBoard->getSideLength()-2);
	theBoard->placeShip(DESTROYER, row, col,0,true);
	if(!worked)
	{
		puts("Placement of destroyer didn't work.");
	}
	theBoard->displayBoard();//five vessels, horizontal



	return answer;

}
bool Production::getYesNo(char* query)
{
	bool answer = true; //so far
	char said = 'x';
	do
	{
		printf("%s (y/n):",query);
		fflush(stdout);
		fflush(stdin);
		scanf("%c",&said);
	}while((said!= 'y')&&(said!='n'));
	if(said=='n')
	{
		answer=false;
	}


	return answer;
}


