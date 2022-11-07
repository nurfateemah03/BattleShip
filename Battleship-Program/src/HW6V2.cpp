//============================================================================
// Name        : HW6V2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Production.h"
#include "Tests.h"
using namespace std;

int main(int argc, char* argv[]) {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Tests* tsP = new Tests();
	if(tsP->tests())
	{
		Production* pP = new Production();
		pP->prod(argc, argv);
		delete pP;
	}
	return 0;
}
