/*
 * Board.cpp
 *
 *  Created on: Mar 3, 2022
 *      Author: theresesmith
 */

#include "Board.h"

Board::Board() {
	// TODO Auto-generated constructor stub
	sideLength=10;
	players = 2;
	seasP = (Space**) malloc(players*sideLength*sideLength*sizeof(Space*));
}

Board::~Board() {
	// TODO Auto-generated destructor stub
}
void Board::welcomeScreen(void) {
	printf ("XXXXX   XXXX  XXXXXX XXXXXX XX     XXXXXX  XXXXX XX  XX XX XXXX\n");
	printf ("XX  XX XX  XX   XX     XX   XX     XX     XX     XX  XX XX XX  XX\n");
	printf ("XXXXX  XX  XX   XX     XX   XX     XXXX    XXXX  XXXXXX XX XXXX\n");
	printf ("XX  XX XXXXXX   XX     XX   XX     XX         XX XX  XX XX XX\n");
	printf ("XXXXX  XX  XX   XX     XX   XXXXXX XXXXXX XXXXX  XX  XX XX XX\n");
	printf ("\n\n");
	printf ("RULES OF THE GAME:\n");
	printf ("1. This is a two player game.\n");
	printf ("2. Player 1 is you and Player 2 is the computer.\n");
	printf ("3. Player 1 will be prompted if user wants to manually input coordinates\n");
	printf ("   for the game board or have the computer randomly generate a game board\n");
	printf ("4. There are five types of ships to be placed by longest length to the\n");
	printf ("   shortest; [c] Carrier has 5 cells, [b] Battleship has 4 cells, [r] Cruiser\n");
	printf ("   has 3 cells, [s] Submarine has 3 cells, [d] Destroyer has 2 cells\n");
	printf ("5. The computer randomly selects which player goes first\n");
	printf ("6. The game begins as each player tries to guess the location of the ships\n");
	printf ("   of the opposing player's game board; [*] hit and [m] miss\n");
	printf ("7. First player to guess the location of all ships wins\n\n");
}
void Board::init()
{
	for(int player = 0; player<2; player++)
	{


		for(int row = 0; row<sideLength; row++)
		{
			for( int col = 0; col<sideLength; col++)
			{
				Space** where = seasP+(sideLength*sideLength*player)+(row*sideLength)+col;
				Space* x = (Space*) malloc(sizeof(Space));
				*where = x;
				x->row = row;
				x->col = col;
				x->hasBeenShot = false;
				x->partOfSunken = false;
				x->symbol = '~';
			}
		}
	}
}
void Board::displayBoard()
{
	for(int player = 0; player<2; player++)
	{
		for(int row = 0; row<sideLength; row++)
		{
			for( int col = 0; col<sideLength; col++)
			{
				Space** where = seasP+(sideLength*sideLength*player)+(row*sideLength)+col;
				Space* x = *where;
				char symbol = x->symbol;
				printf("|%c", symbol);
			}
			puts("|");
		}
		printf("Above is board for player %d\n", player);
	}
	puts(""); fflush(stdout);
}
bool Board::placeShip(ShipType st, int row, int col, int player, bool horizontal)
{
	Carrier* c;
	Battleship* b;
	Cruiser* cr;
	Submarine* s;
	Destroyer* d;
	bool worked = true;
	switch(st)
	{
	case CARRIER:
		c= new Carrier();
		worked = place(c, row, col, player, horizontal);
		break;
	case BATTLESHIP:
		b = new Battleship();
		worked = place(b, row, col, player, horizontal);
		break;
	case CRUISER:
		cr = new Cruiser();
		worked = place(cr, row, col, player, horizontal);
		break;
	case SUBMARINE:
		s=new Submarine();
		worked = place(s, row, col, player, horizontal);
		break;
	case DESTROYER:
		d=new Destroyer();
		worked = place(d, row, col, player, horizontal);
		break;
	default:
		puts("Unexpected value for ship type");
		break;
	}
	return worked;
}
bool Board::place(Carrier* c, int row, int col, int player, bool horizontal){
int compartments = c->getLength();

	bool worked = true;
	int r = row;
	int cl = col;
	//first check

	for(int i = 0; i < compartments && worked; i++)
	{
		Space** where = seasP+(sideLength*sideLength*player)+(r*sideLength)+cl;
		Space* x = *where;
		bool ok = x->symbol=='~';
		if(!ok)
		{
			worked = false;
		}
		if(horizontal)
		{
			cl++;
		}
		else
		{
			r++;
		}
	}
	if(worked)
	{
		int r = row;
		int cl = col;
		//first check
		for(int i = 0; i< compartments && worked; i++)
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
	return worked;
}
bool Board::place(Battleship* b, int row, int col, int player, bool horizontal)
{
	bool worked = true;
	int r = row;
	int c = col;
	int compartments = b->getLength();

	for(int i = 0; i< compartments && worked; i++)
	{
		Space** where = seasP+(sideLength*sideLength*player)+(r*sideLength)+c;
		Space* x = *where;
		bool ok = x->symbol=='~';
		if(!ok)
		{
			worked = false;
		}
		if(horizontal)
		{
			c++;
		}
		else
		{
			r++;
		}
	}
	if(worked)
	{
		int r = row;
		int c = col;
		for(int i = 0; i< compartments && worked; i++)
		{

			Space** where = seasP+(sideLength*sideLength*player)+(r*sideLength)+c;
			Space* x = *where;
			x->symbol = 'B';
			if(horizontal)
			{
				c++;
			}
			else
			{
				r++;
			}
		}
	}
	return worked;
}
bool Board::place(Cruiser* c, int row, int col, int player, bool horizontal)
{
	bool worked = true;
	int r = row;
	int cl = col;
	int compartments = c->getLength();

	for(int i = 0; i< 3 && worked; i++)
	{

		Space** where = seasP+(sideLength*sideLength*player)+(r*sideLength)+cl;
		Space* x = *where;
		bool ok = x->symbol=='~';
		if(!ok)
		{
			worked = false;
		}
		if(horizontal)
		{
			cl++;
		}
		else
		{
			r++;
		}
	}
	if(worked)
	{
		int r = row;
		int cl = col;
		for(int i = 0; i< compartments; i++)
		{

			Space** where = seasP+(sideLength*sideLength*player)+(r*sideLength)+cl;
			Space* x = *where;
			x->symbol='c';
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
	return worked;
}
bool Board::place(Submarine* s, int row, int col, int player, bool horizontal)
{
	bool worked = true;
	int r = row;
	int c = col;
	int compartments = s->getLength();
	for(int i = 0; i< compartments && worked; i++)
	{

		Space** where = seasP+(sideLength*sideLength*player)+(r*sideLength)+c;
		Space* x = *where;
		bool ok = x->symbol=='~';
		if(!ok)
		{
			worked = false;
		}
		if(horizontal)
		{
			c++;
		}
		else
		{
			r++;
		}
	}
	if(worked)
	{
		int r = row;
		int c = col;
		for(int i = 0; i< compartments; i++)
		{

			Space** where = seasP+(sideLength*sideLength*player)+(r*sideLength)+c;
			Space* x = *where;
			x->symbol='S';
			if(horizontal)
			{
				c++;
			}
			else
			{
				r++;
			}
		}
	}
	return worked;
}
bool Board::place(Destroyer* d, int row, int col, int player, bool horizontal)
{
	bool worked = true;
	int r = row;
	int c = col;
	int compartments = d->getLength();

	for(int i = 0; i< 2; i++)
	{

		Space** where = seasP+(sideLength*sideLength*player)+(r*sideLength)+c;
		Space* x = *where;
		bool ok = x->symbol=='~';
		if(!ok)
		{
			worked = false;
		}
		if(horizontal)
		{
			c++;
		}
		else
		{
			r++;
		}
	}
	if(worked)
	{
		int r = row;
		int c = col;
		for(int i = 0; i< compartments; i++)
		{

			Space** where = seasP+(sideLength*sideLength*player)+(r*sideLength)+c;
			Space* x = *where;
			x->symbol='D';
			if(horizontal)
			{
				c++;
			}
			else
			{
				r++;
			}
		}
	}
	return worked;
}
int Board::getRandomNumber (int lowest, int highest) {
	int range = highest - lowest +1;
	int answer = rand()%range + lowest;
	return answer;

}
int Board::getSideLength(){
	return sideLength;
}

