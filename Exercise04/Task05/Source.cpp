//
// Created by Yves Boutellier on 06.11.20.
//
#include "Between.h"
#include <iostream>
#include <vector>

#include <forward_list>

int main(){
    std::vector<int> a = {1,2,3,4,5,6,7,8,9,10};

    std::vector<int>::iterator fst = a.begin();
    std::vector<int>::iterator btwn = ++a.begin();
    std::vector<int>::iterator lst = a.end();

    std::cout << "True or False: "<< between(fst, lst, btwn) << std::endl;
    /*std::cout << *fst << std::endl;
    std::cout << *btwn << std::endl;
    std::cout << *lst << std::endl;*/

    std::forward_list<int> b = {1,2,3,4,5,6,7,8,9,10};

    std::forward_list<int>::iterator first = b.begin();
    std::forward_list<int>::iterator betw = b.end();
    std::forward_list<int>::iterator last = ++b.begin();

    std::cout <<  "True or False: "<< between(first,last,betw) << std::endl;
    /*std::cout << *first << std::endl;
    std::cout << *betw << std::endl;
    std::cout << *last << std::endl;*/





}