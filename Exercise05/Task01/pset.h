//
// Created by Yves Boutellier on 20.11.20.
//

#ifndef EXERCISE05_PSET_H
#define EXERCISE05_PSET_H


#include <string>
#include <set>

#include "persistor.h"

using namespace std;

template<typename T, typename P = persistor<T> >
class pset {
    string filename;
    set <T> s;
    //typename vector<T>::iterator cur = v.begin(), fst = v.begin(), lst = v.end();
public:
    typedef typename set<T>::iterator iterator;
    typedef P persistor;

    pset(string fname) : filename(fname) { readvector(); }
    ~pset() { writevector(); }
    iterator find(const T el) { return s.find(el); }
    iterator begin() { return s.begin(); }
    iterator end() { return s.end(); }

    void insert(const T& el) { s.insert(el); }
    void erase(const T el) { s.erase(el); }
    void erase(iterator it) { s.erase(it); }

    void writevector() {
        ofstream ofs(filename);
        //typename vector<T>::iterator fst = v.begin(), lst = v.end();
        iterator cur = s.begin();
        iterator lst = s.end();
        while (cur != lst) { persistor::write_element(ofs, *cur++); }
    }
    void readvector() {
        ifstream ifs(filename);

        for (;;) {
            T x;
            x = persistor::read_element(ifs);
            if (!ifs.good()) break;
            s.insert(x);
        }


    }

    friend ostream& operator<< (ostream& os, pset& pout) {
        iterator cur = pout.s.begin();
        iterator lst = pout.s.end();
        while (cur != lst) os << *cur++ << endl;
        return(os);
    }
};


#endif //EXERCISE05_PSET_H
