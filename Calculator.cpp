/*
 * Calculator.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Ben
 */
#include "Calculator.h"
#include "LinkedStack.h"
#include <string>
#include <sstream>

Calculator::Calculator(){

}

void Calculator::processInput(){
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

int Calculator::compute(string inputStr){
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


	switch(op){
	case '+':
		break;
	case '-':
		break;
	case '/':
		break;
	case '*':
		break;
	case '%':
		break;
	default: cout << "Invalid operator.";
	}
}


int Calculator::undo(){

}


int Calculator::redo(){

}

int Calculator::clear(){

}

