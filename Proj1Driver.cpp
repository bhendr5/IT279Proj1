/*
 * Proj1Driver.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Ben
 */
#include <algorithm>
#include "linkedQueue.h"
#include "Calculator.h"
using namespace std;

// Parse out a number from text
int numInput(string str) {
  int parseOp;
  try {
    parseOp = atoi(str.c_str());
  } catch (...) {}
  return parseOp;
}


int oldMain(){
	int input = 0;

	cout << "Enter 1 for calculator or 2 for checkout line: ";
	cin >> input;

	if(input == 2){
        linkedQueue<int> *line = new linkedQueue<int>;
        string input;
        cout << "Customers will arrive in random integer intervals of 1 to x minutes" << endl;
        cout << "Please enter a number for x: " << endl;
        cin >> input;

        // Converts str input to int x
        int x = numInput(input);

        // int's to keep track of the customers and time along with random number generator
        int longestWait = 0;
        int maxLength = 0;
        int TIME = 0;
        int next = rand() % x + (TIME+1);
        int serveTime;
        int custNum = 1;

        // Skip ahead to the first arrival time
        TIME = next;
        serveTime = TIME + (rand() % x + 1);

            while (TIME < 720) {
            // if a customer leaves at the specified time
            if (TIME == serveTime) {
                cout << "Customer " << custNum << " left at " << TIME << '.' << endl;
                custNum ++;
                // randomly produce next leaving event
                int serviceTime = rand() % x + 1;
                serveTime = TIME + serviceTime;

                int nextCustomer = line->removeFrontOfQueue();
            if (nextCustomer) {
                longestWait = max(longestWait, (TIME - nextCustomer));
      }
    }
            // if a customer arrives at the specified time
        if (TIME == next) {
            cout << "Customer " << custNum + line->length << " arrived at " << TIME << '.' << endl;
            line->addEndQueue(next);
            // Randomly produce next arrival time
            next = rand() % x + (TIME+1);

            // Recording longest line
            maxLength = max(maxLength, line->length);
    }
            // Go to next time
            TIME = min(next, serveTime);
  }

  cout << "\nLongest queue length: " << maxLength << endl;
  cout << "Longest wait for one customer: " << longestWait << endl;

	}

	else{
		cout << "Invalid input.";
	}

	return 0;
}


