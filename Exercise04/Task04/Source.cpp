//
// Created by Yves Boutellier on 06.11.20.
//

#include <iostream>
#include <vector>
#include <iterator>
#include "MergeSTL.h"
#include <list>
#include <forward_list>

int main(){
    std::vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    std::list<int> b = {10,11,12,13,14,15,16,17,18,19,20};
    std::forward_list<int> e = {44,55,66};
    std::forward_list<int> c = merge(e,a);

    /*
    std::vector<float> d = {3.14,2.71};
    std::vector<float> f = {9.9,1.1};
    std::vector<float> e = merge(d,f);*/

    for (auto i : c){
        std::cout << i << std::endl;
    }

}