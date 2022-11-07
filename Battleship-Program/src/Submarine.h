/*
 * Submarine.h
 *
 *  Created on: Mar 3, 2022
 *      Author: theresesmith
 */

#ifndef SUBMARINE_H_
#define SUBMARINE_H_

class Submarine {
public:
	Submarine();
	virtual ~Submarine();
	bool isSunk();
	void takeAHit();
	int getLength();


private:
	char symbol;
	int compartments;//how much space in the sea
	//also how hits it can sustain
	int hitsSustained; //initially 0, but can count up
};


#endif /* SUBMARINE_H_ */
