/*
 * stack.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Ben
 */

#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include <iostream>

class StackNode{
public:
	char char1 = NULL;
	int int1 = 0,int2 = 0;
	StackNode *next = nullptr;
	StackNode(int int1, int int2, StackNode *next);
	StackNode(int int1, StackNode *next);
	StackNode(int int1, int int2, char char1, StackNode *next);
	StackNode(int int1, char char1, StackNode *next);
	StackNode(char char1, StackNode *next);
	StackNode();
};

class LinkedStack{
public:
	StackNode *head = nullptr;
	int size = 0;
	void push(int int1, int int2, char char1);
	void push(int int1, int int2);
	void push(int int1, char char1);
	void push(int int1);
	void push(char char1);
	StackNode pop();
	StackNode peek();
	bool isEmpty();
	int findSize();
};



#endif /* LINKEDSTACK_H_ */
