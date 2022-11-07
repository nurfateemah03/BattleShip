/*
 * Destroyer.cpp
 *
 *  Created on: Mar 3, 2022
 *      Author: theresesmith
 */

#include "Destroyer.h"
Destroyer::Destroyer() {
	symbol = 'D';
	compartments = 2;
	hitsSustained = 0;
}
Destroyer::~Destroyer() {
	// TODO Auto-generated destructor stub
}

bool Destroyer::isSunk(){
	return false;
}
void Destroyer::takeAHit(){
	hitsSustained++;
}
int Destroyer::getLength(){
	return compartments;

}
