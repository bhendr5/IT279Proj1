/*
 * Calculator.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Ben
 */
#include "Calculator.h"
#include <string>
#include <sstream>

Calculator::Calculator(){
	carryResult = 0;
	primaryStack = new LinkedStack();
	undoStack = new LinkedStack();
}

void Calculator::processInput(){

	while(true){

		string inputStr;
		cout << ">";
		cin >> inputStr;

		//Clear
		if(inputStr == "C"){
			this->clear();
		}

		//Undo
		else if(inputStr == "U"){
			this->undo();
		}

		//Redo
		else if(inputStr == "R"){
			this->redo();
		}

		//Quit
		else if(inputStr == "Q"){
			cout << endl << "Goodbye";
			return;
		}

		//Looks for operator then calls compute
		else if(inputStr[0] == '-' || inputStr[0] == '+' || inputStr[0] == '/' ||
				inputStr[0] == '*' || inputStr[0] == '%'){
			this->compute(inputStr);
		}

		//Catches invalid inputs
		else{
			cout << endl << "Invalid input.";
			this->processInput();
		}
	}
}

void Calculator::compute(string inputStr){
	int strLen;
	int intOperand;
	char op = inputStr[0];


	//Measures length of input string
	std::stringstream strStream(inputStr);
	string n;
	while(strStream){
		strStream>>n;
		if(strStream)
			strLen++;
	}

	//Converts string to int
	intOperand = stoi(inputStr.substr(1, strLen));

	//Pushes result of last computation as int1
	primaryStack->push(op,carryResult,intOperand);

	switch(op){
	case '+': carryResult = primaryStack->peek().int1+primaryStack->peek().int2;
	break;
	case '-': carryResult = primaryStack->peek().int1-primaryStack->peek().int2;
	break;
	case '/': carryResult = primaryStack->peek().int1/primaryStack->peek().int2;
	break;
	case '*': carryResult = primaryStack->peek().int1*primaryStack->peek().int2;
	break;
	case '%': carryResult = primaryStack->peek().int1%primaryStack->peek().int2;
	break;
	default: cout << "Invalid operator.";
	}

	cout << carryResult;
}


void Calculator::undo(){

}


void Calculator::redo(){

}

void Calculator::clear(){

}

