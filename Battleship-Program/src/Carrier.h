/*
 * Carrier.h
 *
 *  Created on: Mar 3, 2022
 *      Author: theresesmith
 */

#ifndef CARRIER_H_
#define CARRIER_H_

class Carrier {
public:
	Carrier();
	virtual ~Carrier();
	bool isSunk();
	void takeAHit();
	int getLength();


private:
	char symbol;
	int compartments;//how much space in the sea
	//also how hits it can sustain
	int hitsSustained; //initially 0, but can count up
};

#endif /* CARRIER_H_ */
