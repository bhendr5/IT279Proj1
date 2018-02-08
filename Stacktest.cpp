/*
 * Stacktest.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Ben
 */

#include "LinkedStack.h";

int main(){
	LinkedStack *s = new LinkedStack();
	s->push(1,2,'+');
	s->push(1,3,'+');
	s->push(1,4,'-');


	delete s;
	s = nullptr;
}

