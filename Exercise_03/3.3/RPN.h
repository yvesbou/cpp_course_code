
#include <iostream>
#include <vector>
#include "pvector.h"
#include <sstream>
template <typename T>
int RPN(string savefile) {
    pvector<T> stack(savefile);
    string line;
    //variables for parsing commands
    T temp;
    string temp_s;

    for (;;) {
        for (int i = 0; i < size(stack.v); i++) { cout << "n" << i + 1 << ": " << stack.v[i] << endl; }
        cout << "Command: ";
        getline(cin, line);
        istringstream com_parse(line);
        for (;;) {
            if (com_parse >> temp_s) {
                if (temp_s == "n") {   // if the command is n then we read in the element
                    if (!(com_parse >> temp)) { return 1; };  //if there is no element after n, we terminate the program
                    stack.push_back(temp);   // push back adds an element to the end of the vector
                }
                if (temp_s == "q") { return 0; } // terminates the program
                if (temp_s == "d") { stack.pop_back(); } // pop back removes the last element of the vector
                if (temp_s == "+") {
                    temp = stack.v[size(stack.v) - 2] + stack.v[size(stack.v) - 1];
                    stack.pop_back(); //remove last two elements after calculation
                    stack.pop_back();
                    stack.push_back(temp);
                }
                if (temp_s == "-") {
                    temp = stack.v[size(stack.v) - 2] - stack.v[size(stack.v) - 1];
                    stack.pop_back();
                    stack.pop_back();
                    stack.push_back(temp);
                }
                if (temp_s == "*") {
                    temp = stack.v[size(stack.v) - 2] * stack.v[size(stack.v) - 1];
                    stack.pop_back();
                    stack.pop_back();
                    stack.push_back(temp);
                }
                if (temp_s == "/") {
                    temp = stack.v[size(stack.v) - 2] / stack.v[size(stack.v) - 1];
                    stack.pop_back();
                    stack.pop_back();
                    stack.push_back(temp);
                }

                if (temp_s == "min") {

                    if (abs(stack.v[size(stack.v) - 2]) > abs(stack.v[size(stack.v) - 1])){
                        stack.pop_back();
                        stack.pop_back();
                        stack.push_back(stack.v[size(stack.v) - 1]);
                    }else{
                        stack.pop_back();
                        stack.pop_back();
                        stack.push_back(stack.v[size(stack.v) - 2]);
                    }
                }
            }
            else { break; } //stop reading the input line, if there are no characters left
        }
    }
}