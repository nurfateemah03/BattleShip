/*
 * Battleship.cpp
 *
 *  Created on: Mar 3, 2022
 *      Author: theresesmith
 */

#include "Battleship.h"

Battleship::Battleship() {
	symbol = 'B';
	compartments = 4;
	hitsSustained = 0;
}
Battleship::~Battleship() {
	// TODO Auto-generated destructor stub
}

bool Battleship::isSunk(){
	return false;
}
void Battleship::takeAHit(){
	hitsSustained++;
}
int Battleship::getLength(){
	return compartments;

}
