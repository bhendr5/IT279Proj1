/*
 * Stacktest.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Ben
 */

#include <iostream>;
#include "Calculator.h";
using namespace std;

int main(){
	int input = 0;

	cout << "Enter 1 for calculator or 2 for checkout line: ";
	cin >> input;
	if(input == 1){
		Calculator *calc = new Calculator();
		calc->processInput();
	}

	else if(input == 2){

	}

	else{
		cout << "Invalid input.";
	}

	return 0;
}


