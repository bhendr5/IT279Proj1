/*
 * stack.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Ben
 */

#include <string>
#include "LinkedStack.h"
using namespace std;


StackNode::StackNode(int int1, int int2, char char1, StackNode *next){
	this->int1 = int1;
	this->int2 = int2;
	this->char1 = char1;
	this->next = next;
}

void LinkedStack::push(char char1, int int1, int int2) {
	StackNode *temp = new StackNode(int1, int2, char1, head);
	head = temp;
	size++;
}

StackNode LinkedStack::pop(){
	if (isEmpty()) {
		cout << "Error. Stack is empty.";
	}

	else {
		StackNode *result = head;
		head = head->next;
		return *result;
	}
}

StackNode LinkedStack::peek(){
	if (isEmpty()) {
		cout << "Error. Stack is empty.";
	}

	else {
		return *head;
	}
}

bool LinkedStack::isEmpty(){
	return this->head == nullptr;
}

int LinkedStack::findSize(){
	return this->size;
}


