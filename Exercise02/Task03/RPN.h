#pragma once
#ifndef RPN_H_
#define RPN_H_
#include <iostream>
#include <vector>
#include "pvector.h"
template <typename T>
int RPN(string savefile) {
	pvector<T> stack(savefile);     //a vector of type int
	typename vector<T>::iterator it = stack.v.end();
	string line;
	//variables for parsing commands
	T temp;
	string temp_s;
	
	for (;;) {
		for (int i = 0; i < (int)size(stack.v); i++) { cout << "n" << i + 1 << ": " << stack.v[i] << endl; }
		cout << "Command: ";
		getline(cin, line);
		istringstream com_parse(line);
		for (;;) {
			if (com_parse >> temp_s) { // all commands are of length 1, therefore we can stream into a character
				if (temp_s == "n") {   // if the command is n then we read in the next integer. 
					if (!(com_parse >> temp)) { return 1; };  //if there is no int after n, we terminate the programm
					stack.push_back(temp);   // push back adds an element to the end of the vector
				}
				if (temp_s == "q") { return 0; }
				if (temp_s == "d") { stack.pop_back(); } // pop back removes the last element of the vector
				if (temp_s == "+") {
					//it = stack.end();
					//temp_num = *it + *it++;
					// last element of a vector is size(vecor) -1, because index starts at 1
					temp = stack[size(stack.v) - 2] + stack[size(stack.v) - 1];
					stack.pop_back();										//remove last two elements after calculation
					stack.pop_back();
					stack.push_back(temp);
				}
				if (temp_s == "-") {
					temp = stack[size(stack.v) - 2] - stack[size(stack.v) - 1];
					stack.pop_back();
					stack.pop_back();
					stack.push_back(temp);
				}
				if (temp_s == "*") {
					temp = stack[size(stack.v) - 2] * stack[size(stack.v) - 1];
					stack.pop_back();
					stack.pop_back();
					stack.push_back(temp);
				}
				if (temp_s == "/") {
					temp = stack[size(stack.v) - 2] / stack[size(stack.v) - 1];
					stack.pop_back();
					stack.pop_back();
					stack.push_back(temp);
				}
				if (temp_s == "min") {
					temp = min(stack[size(stack.v) - 2], stack[size(stack.v) - 1]);
					stack.pop_back();
					stack.pop_back();
					stack.push_back(temp);
				}
			}
			else { break; } //stop reading the input line, if there are no characters left
		}
	}
}
#endif