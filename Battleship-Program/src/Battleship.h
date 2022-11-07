/*
 * Battleship.h
 *
 *  Created on: Mar 3, 2022
 *      Author: theresesmith
 */

#ifndef BATTLESHIP_H_
#define BATTLESHIP_H_

class Battleship {
public:
	Battleship();
	virtual ~Battleship();
	bool isSunk();
	void takeAHit();
	int getLength();


private:
	char symbol;
	int compartments;//how much space in the sea
	//also how hits it can sustain
	int hitsSustained; //initially 0, but can count up
};


#endif /* BATTLESHIP_H_ */
