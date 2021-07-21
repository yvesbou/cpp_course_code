//
// Created by Yves Boutellier on 09.10.20.
//

#ifndef EXERCISE02_TASK01_H
#define EXERCISE02_TASK01_H
#include <iostream>
#include <vector>
#include <fstream>
#include "../Task03/fraction.h"


template <typename T>
class pvector {
    std::string filename;
    std::vector<T> v;

    void readvector(){
        std::ifstream ifs (filename);
        // read the input file stream into the vector, called when creating class instance
        for(;;){
            T x; ifs >> x; if(!ifs.good()){break;}
            v.push_back(x);
        }
    };

    void writevector(){
        std::ofstream ofs(filename);
        // write the vector into a file, called when destructor of class instance is called
        // iterate over the pointers of the vector and increment until pointer is the end pointer
        typename std::vector<T>::iterator fst=v.begin(), lst=v.end();
        while (fst!=lst){ofs << *fst++ << std::endl;}
    }

public:
    pvector(std::string fname) : filename(fname) {readvector();} // constructor
    pvector(const pvector&){std::cout << "vector got copied!";} // copy constructor
    ~pvector() { writevector();} // when scope is left the destructor gets called, writevector function is called

    // some public functions to modify the vector
    void push_back(const T &el) {v.push_back(el);} //reference because we don't want to make a copy
    void pop_back(){v.pop_back();}
    int size(){return v.size();}
    T operator[](int i){
        return v[i];
    }
    T end(){
        return v.end();
    }

};

// template specialization for bools
template<>
class pvector<bool>{
    std::string filename;
    std::vector<bool> v;

    void readvector(){
        std::ifstream ifs (filename);
        for(;;){
            bool x; ifs >> x; if(!ifs.good()){break;}
            v.push_back(x);
        }
    };

    void writevector(){
        int i;
        std::ofstream ofs(filename);
        // cannot use the pointer since one bool element is stored in one bit
        for(i=0; i < v.size();i++){ofs << v[i] << std::endl;}
    }

public:
    pvector(std::string fname) : filename(fname) {readvector();}
    ~pvector() { writevector();} // when scope is left, writevector function is called

    void push_back(const bool &el) {v.push_back(el);} //reference because we don't want to make a copy
    void pop_back(){v.pop_back();}


};



#endif //EXERCISE02_TASK01_H
