#pragma once
#include <string>
#include <vector>

#include "persistor.h"

using namespace std;

template<typename T, typename P = persistor<T> >
class pvector {
	string filename;
	vector<T> v;

public:
	typedef typename vector<T>::iterator iterator;
	typedef P persistor;

	pvector(string fname) : filename(fname) { readvector(); }
	~pvector() { writevector(); }
	void push_back(const T& el) { v.push_back(el); }
	void pop_back() { v.pop_back(); }

	void writevector() {
		ofstream ofs(filename);

		iterator cur = v.begin();
		iterator lst = v.end();
		while (cur != lst) persistor::write_element(ofs, *cur++);
	}
	void readvector() {
		ifstream ifs(filename);

		for (;;) {
			T x;
			x = persistor::read_element(ifs);
			if (!ifs.good()) break;
			v.push_back(x);
		}


	}
	T operator[] (int index) {
		return v[index];
	}
	friend ostream& operator<< (ostream& os, pvector& pout) {
		iterator cur = pout.v.begin();
		iterator lst = pout.v.end();
		while (cur != lst) os << *cur++ << endl;
		return(os);
	}
};