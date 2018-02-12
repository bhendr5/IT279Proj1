/*
 * Calculator.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Ben
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include <iostream>
using namespace std;

class Calculator{
public:
	//Parses input and calls appropriate function
	void processInput();
	//Perfoms arthmetic operation and returns result
	int compute(string inputStr);

	int redo();
	int undo();
	int clear();

	//Default constructor that creates two stacks
	//One stack holds previous results of computations and the other holds
	//"future" results for redoing
	Calculator();
};



#endif /* CALCULATOR_H_ */
