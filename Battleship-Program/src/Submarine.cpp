/*
 * Submarine.cpp
 *
 *  Created on: Mar 3, 2022
 *      Author: theresesmith
 */

#include "Submarine.h"

Submarine::Submarine() {
	symbol = 'S';
	compartments = 3;
	hitsSustained = 0;
}
Submarine::~Submarine() {
	// TODO Auto-generated destructor stub
}

bool Submarine::isSunk(){
	return false;
}
void Submarine::takeAHit(){
	hitsSustained++;
}
int Submarine::getLength(){
	return compartments;

}
