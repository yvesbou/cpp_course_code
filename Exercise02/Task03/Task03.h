//
// Created by Yves Boutellier on 09.10.20.
//
#include <iostream>
#include <sstream>
#include <utility>
#include "../Task01/Task01.h"
#include "fraction.h"
#ifndef EXERCISE02_TASK03_H
#define EXERCISE02_TASK03_H


template<typename T>
inline T min(T a, T b) {
    return std::min(a,b); };

template<>
inline fraction min(fraction x, fraction y){
    double a = x.c/x.d;
    double b = y.c/y.d;
    if (a < b){
        return x;
    }
    else{return y;}
}


template <typename R>
class RPN {
    std::string filename;
    char quitter;
    std::string line;
    std::string element;
    R inputElement;
    R tempElement;

public:
    RPN(std::string fname) : filename(fname) {
        pvector<R> stack (filename);

        while (quitter != 'q'){
            for (int i = 0; i < stack.size(); i++) {
                std::cout << i + 1 << ". :" << stack[i] << std::endl;}
            std::getline(std::cin, line);
            std::istringstream iss(line);

            while (iss >> element) {

                if (element == "d") {
                    stack.pop_back();
                }
                if (element == "q") {
                    quitter = 'q';
                }
                if (element == "n") {
                    iss >> inputElement; // fraction
                    stack.push_back(inputElement); // fraction
                }
                if (element == "+") {
                    tempElement = stack[stack.size()-2] + stack[stack.size()-1];
                    stack.pop_back();
                    stack.pop_back();
                    stack.push_back(tempElement);
                }
                if (element == "-") {
                    tempElement = stack[stack.size()-2] - stack[stack.size()-1];
                    stack.pop_back();
                    stack.pop_back();
                    stack.push_back(tempElement);
                }
                if (element == "/") {
                    tempElement = stack[stack.size()-2] / stack[stack.size()-1];
                    stack.pop_back();
                    stack.pop_back();
                    stack.push_back(tempElement);
                }
                if (element == "*") {
                    tempElement = stack[stack.size()-2] * stack[stack.size()-1];
                    stack.pop_back();
                    stack.pop_back();
                    stack.push_back(tempElement);
                }
                if (element == "min") {
                    tempElement = min(stack[stack.size()-2], stack[stack.size()-1]);
                    stack.pop_back();
                    stack.pop_back();
                    stack.push_back(tempElement);
                }
            }

        }}
};

#endif //EXERCISE02_TASK03_H
