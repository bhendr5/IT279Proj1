/*
 * Calculator.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Ben
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include "LinkedStack.h"

class Calculator{
public:
	LinkedStack *primaryStack;
	LinkedStack *undoStack;
	int carryResult;

	//Parses input and calls appropriate function
	void processInput();

	//Performs arithmetic operation and returns result
	void compute(string inputStr);

	void redo();
	void undo();
	void clear();

	//Default constructor that creates two stacks
	//One stack holds primary line of results while other holds
	//"undone" results in case they need to be redone
	Calculator();
};



#endif /* CALCULATOR_H_ */
