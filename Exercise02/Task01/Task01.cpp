//
// Created by Yves Boutellier on 09.10.20.
//

#include "Task01.h"
#include <vector>

// passing pvector into a function and using reference to avoid invoking the copy constructor
void finisher(pvector<int> &vec){
    if (vec.size() < 10){
        vec.push_back(10);
    }
};


int main(){
    pvector<int> v0 ("pvector-int.txt");
    v0.push_back(9);
    pvector<double> v1 ("pvector-double.txt");
    v1.push_back(3.14);
    pvector<bool> v2 ("pvector-bool.txt");
    v2.push_back(true);
    pvector<char> v3 ("pvector-char.txt");
    v3.push_back('z');
    pvector<std::string> v4 ("pvector-string.txt");
    v4.push_back("theEnd");
    finisher(v0);

}