//
// Created by Yves Boutellier on 18.11.20.
//

#include "Header.h"
#include "lastWeek.h"
#include <vector>
#include <iostream>
#include <list>
#include <forward_list>
#include <set>

int main(){

    //this week
    std::vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> b = {1,2,3,4,5,6,7,8,9,10};
    std::set<int> s = {1001,682,1154};
    std::list<int> d = {11,22,33};
    std::forward_list<int> e = {44,55,66};

    //std::vector<int> c = merge(a,d); //works
    //std::list<int> c = merge(d,a); //works
    //std::forward_list<int> c = merge(e,a); //error: no member named 'push_back'

    auto r = merge<std::forward_list<int>, std::vector<int> >(e,a); //works

    for (auto i : r){
        std::cout << i << std::endl;
    }


    //last week
    /*
    std::vector<int> a2 = {1,2,3,4,5,6,7,8,9,10};
    std::list<int> b2 = {10,11,12,13,14,15,16,17,18,19,20};
    std::forward_list<int> e2 = {44,55,66};
    std::set<int> s2 = {1001,682,1154};
    std::vector<int> d2 = Merge(a2,e2); //works
    //std::forward_list<int> c2 = Merge(e2,a2); //error: no member named 'insert'
    //std::vector<int> r = Merge(a2,s2); //works
    std::set<int> r2 = Merge(s2,a2); //error: no matching member function for call to 'insert'


    for (auto i : r2){
        std::cout << i << std::endl;
    }*/
}
