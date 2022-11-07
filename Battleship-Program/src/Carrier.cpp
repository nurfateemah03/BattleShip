/*
 * Carrier.cpp
 *
 *  Created on: Mar 3, 2022
 *      Author: theresesmith
 */

#include "Carrier.h"

Carrier::Carrier() {
	symbol = 'C';
	compartments = 5;
	hitsSustained = 0;
}
Carrier::~Carrier() {
	// TODO Auto-generated destructor stub
}

bool Carrier::isSunk(){
	return false;
}
void Carrier::takeAHit(){
	hitsSustained++;
}
int Carrier::getLength(){
	return compartments;
}

