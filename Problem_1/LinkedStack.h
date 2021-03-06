/*
 * stack.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Ben
 */

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include <iostream>
#include <string>
using namespace std;

class StackNode{
public:
	char char1 = NULL;
	int int1 = 0,result = 0;
	StackNode *next = nullptr;
	StackNode(char char1, int int1, int result, StackNode *next);
	StackNode();
	string toString();
};

class LinkedStack{
public:
	StackNode *head = nullptr;
	int size = 0;
	void push(char char1, int int1, int result);
	void push(StackNode node);

	StackNode pop();
	StackNode peek();
	bool isEmpty();
	int findSize();
};

#endif /* LINKEDSTACK_H_ */
