/*
 * Cruiser.cpp
 *
 *  Created on: Mar 3, 2022
 *      Author: theresesmith
 */

#include "Cruiser.h"


Cruiser::Cruiser() {
	symbol = 'c';
	compartments = 3;
	hitsSustained = 0;
}
Cruiser::~Cruiser() {
	// TODO Auto-generated destructor stub
}

bool Cruiser::isSunk(){
	return false;
}
void Cruiser::takeAHit(){
	hitsSustained++;
}

int Cruiser::getLength(){
	return compartments;

}
