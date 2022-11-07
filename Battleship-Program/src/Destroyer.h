/*
 * Destroyer.h
 *
 *  Created on: Mar 3, 2022
 *      Author: theresesmith
 */

#ifndef DESTROYER_H_
#define DESTROYER_H_

class Destroyer {
public:
	Destroyer();
	virtual ~Destroyer();
	bool isSunk();
	void takeAHit();
	int getLength();


private:
	char symbol;
	int compartments;//how much space in the sea
	//also how hits it can sustain
	int hitsSustained; //initially 0, but can count up
};


#endif /* DESTROYER_H_ */
