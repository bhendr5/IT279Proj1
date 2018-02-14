/* Patata - Jiasui Ding, Ben Hendrix, Jacob Levin
** IT 279
** ASG 1 Queue
*/
#include <iostream>
#include <string>
using namespace std;

// Node class
template <class T>
class node {
    public:
        T data;
        node<T> *next;
};

// linkedQueue class headers
template <class T>
class linkedQueue {
    public:
        linkedQueue();
        node<T> *head;
        node<T> *tail;
        T length;
        void addEndQueue(T val);
        T removeFrontOfQueue();
        T peek();
};


// Peek front of queue
template <class T>
T linkedQueue<T>::peek() {
    if (head){
        return head->next;
    }
    else{
        return 0;
    }
}

// Constructor
template <class T>
linkedQueue<T>::linkedQueue() {
    head = NULL;
    tail = NULL;
    length = 0;
}


// Method to add an item to the queue
template <class T>
void linkedQueue<T>::addEndQueue(T val) {
    node<T> *n = new node<T>;
    n->data = val;
    n->next = NULL;
    //If the queue is empty
    if (! head) {
        head = tail = n;
        length = 1;
    }
    //Else if the queue has length of 1
    else if (length == 1){
        head->next = tail = n;
        length = 2;
    }
    else{
        tail->next = n;
        length = length + 1;
  }
}

// Remove/return the item at the front of the queue
template <class T>
T linkedQueue<T>::removeFrontOfQueue() {
    //If the queue is empty
    if (! head) {
        return 0;
    }
  T val = head->data;
    if (length == 1) {
        head = tail = NULL;
  }
    else{
        head = head->next;
  }

  length --;
  return val;
}

