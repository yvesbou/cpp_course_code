//
// Created by Yves Boutellier on 05.11.20.
//
#include <iostream>
#include "Range.h"
#include <iostream>


int main(){
    for (auto i : Range(10,20)){
        std::cout << i << std::endl;
    }
}