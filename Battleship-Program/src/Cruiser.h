/*
 * Cruiser.h
 *
 *  Created on: Mar 3, 2022
 *      Author: theresesmith
 */

#ifndef CRUISER_H_
#define CRUISER_H_

class Cruiser {
public:
	Cruiser();
	virtual ~Cruiser();
	bool isSunk();
	void takeAHit();
	int getLength();


private:
	char symbol;
	int compartments;//how much space in the sea
	//also how hits it can sustain
	int hitsSustained; //initially 0, but can count up
};

#endif /* CRUISER_H_ */
