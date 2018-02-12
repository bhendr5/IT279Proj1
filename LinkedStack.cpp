/*
 * stack.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Ben
 */

#define __USE_MINGW_ANSI_STDIO 0
#include "LinkedStack.h"

StackNode::StackNode(int int1, int int2, char char1, StackNode *next){
	this->int1 = int1;
	this->int2 = int2;
	this->char1 = char1;
	this->next = next;
}

string StackNode::toString(){
	return string(1, this->char1) + to_string(this->int1) + to_string(this->int2);
}

void LinkedStack::push(char char1, int int1, int int2) {
	StackNode *temp = new StackNode(int1, int2, char1, head);
	head = temp;
	size++;
}

void LinkedStack::push(StackNode node) {
	StackNode *temp = new StackNode(node);
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




