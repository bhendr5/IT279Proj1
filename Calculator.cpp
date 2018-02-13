/*
 * Calculator.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Ben
 */
#define __USE_MINGW_ANSI_STDIO 0
#include "Calculator.h"
#include <sstream>

Calculator::Calculator(){
	calcResult = 0;
	primaryStack = new LinkedStack();
	undoStack = new LinkedStack();
}

void Calculator::processInput(){

	while(true){

		string inputStr;
		cout << endl << ">";
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

	//Pushes 0 into stack if empty
	if(primaryStack->isEmpty())
		primaryStack->push(NULL,NULL,0);

	switch(op){
	case '+': calcResult = primaryStack->peek().result+intOperand;
	break;
	case '-': calcResult = primaryStack->peek().result-intOperand;
	break;
	case '/': calcResult = primaryStack->peek().result/intOperand;
	break;
	case '*': calcResult = primaryStack->peek().result*intOperand;
	break;
	case '%': calcResult = primaryStack->peek().result%intOperand;
	break;
	default: cout << "Invalid operator.";
	}

	//Pushes operator, operand, and result into stack
	primaryStack->push(op,intOperand,calcResult);

	cout << calcResult;
}


void Calculator::undo(){

	StackNode *temp = new StackNode(primaryStack->peek().char1,
			primaryStack->peek().int1,
			primaryStack->peek().result, undoStack->head);
	primaryStack->pop();
	undoStack->push(*temp);
	cout << primaryStack->peek().result;
}


void Calculator::redo(){
	if(!undoStack->isEmpty()){
		compute(string(1, undoStack->peek().char1) + to_string(undoStack->peek().int1));
		undoStack->pop();
	}

	else{
		cout << "Nothing left to undo." << endl;
	}
}

void Calculator::clear(){

}

