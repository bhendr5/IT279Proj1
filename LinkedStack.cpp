/*
 * stack.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Ben
 */

#include <string>
#include "LinkedStack.h"
using namespace std;

StackNode::StackNode(int int1, int int2, StackNode *next){
	this->int1 = int1;
	this->int2 = int2;
	this->char1 = NULL;
	this->next = next;
}

StackNode::StackNode(int int1, int int2, char char1, StackNode *next){
	this->int1 = int1;
	this->int2 = int2;
	this->char1 = char1;
	this->next = next;
}

StackNode::StackNode(int int1, char char1, StackNode *next){
	this->int1 = int1;
	this->char1 = char1;
	this->int2 = NULL;
	this->next = next;
}

StackNode::StackNode(char char1, StackNode *next){
	this->char1 = char1;
	this->next = next;
	this->int2 = NULL;
	this->int1 = NULL;
}

StackNode::StackNode(int int1, StackNode *next){
	this->int1 = int1;
	this->next = next;
	this->int2 = NULL;
	this->char1 = NULL;
}

StackNode::StackNode(){
	this->int1 = NULL;
	this->next = NULL;
	this->int2 = NULL;
	this->char1 = NULL;
}

void LinkedStack::push(int int1, int int2, char char1) {
	StackNode *temp = new StackNode(int1, int2, char1, head);
	head = temp;
	size++;
}

void LinkedStack::push(int int1, char char1) {
	StackNode *temp = new StackNode(int1, char1, head);
	head = temp;
	size++;
}

void LinkedStack::push(int int1, int int2) {
	StackNode *temp = new StackNode(int1, int2, head);
	head = temp;
	size++;
}

void LinkedStack::push(char char1) {
	StackNode *temp = new StackNode(char1, head);
	head = temp;
	size++;
}

void LinkedStack::push(int int1) {
	StackNode *temp = new StackNode(int1, head);
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


