/*
 * Calculator.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Ben
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include "LinkedStack.h"
#include <iostream>
using namespace std;

class Calculator{
public:
	LinkedStack *primaryStack;
	LinkedStack *undoStack;
	int carryResult;

	//Parses input and calls appropriate function
	void processInput();

	//Perfoms arthmetic operation and returns result
	void compute(string inputStr);

	void redo();
	void undo();
	void clear();

	//Default constructor that creates two stacks
	//One stack holds previous results of computations and the other holds
	//"future" results for redoing
	Calculator();
};



#endif /* CALCULATOR_H_ */
