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

	//Variable to help store calculation results before passing to a stack node
	calcResult = 0;

	//Primary stack holds computation history and results
	primaryStack = new LinkedStack();

	//Undostack holds operations that are undone in case they need to be redone
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


	//Measures length of input string in order to determine integer size
	std::stringstream strStream(inputStr);
	string n;
	while(strStream){
		strStream>>n;
		if(strStream)
			strLen++;
	}

	//Converts string to int
	intOperand = stoi(inputStr.substr(1, strLen));

	//Pushes null node with 0 result into stack if empty
	if(primaryStack->isEmpty()){
		primaryStack->push(NULL,NULL,0);
	}

	//Switch block performs appropriate operation on inputted integer
	//and previous node result
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

	//Empty undoStack
	while( !undoStack->isEmpty() ) {
		undoStack->pop();
	}
	
	cout << calcResult;
}

//Pops a node from primaryStack and pushes into undoStack
void Calculator::undo(){
	undoStack->push(primaryStack->peek().char1,
			primaryStack->peek().int1,
			primaryStack->peek().result);
	primaryStack->pop();
	cout << primaryStack->peek().result;

}

//Pops a node from undoStack and pushes into primaryStack
void Calculator::redo(){
	if(!undoStack->isEmpty()){		
		primaryStack->push(undoStack->peek().char1,
			undoStack->peek().int1,
			undoStack->peek().result);
		undoStack->pop();
		cout << primaryStack->peek().result;
	}

	//If undoStack is empty then there are no operations left to redo
	else{
		cout << "No operations to redo" << endl;
		cout << primaryStack->peek().result;
	}
}

//Pushes a node equal to zero in the stack to perform a clear operation
void Calculator::clear(){
	primaryStack->push('c',0,0);
	cout << primaryStack->peek().result;

}

int main(){
	cout << "Calculator: " << endl;
	Calculator *calc = new Calculator();
	calc->processInput();
}

