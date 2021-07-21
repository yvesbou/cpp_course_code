#pragma once
#pragma once
#include <string>
#include <set>

#include "persistor.h"

using namespace std;

template<typename T, typename P = persistor<T> >
class pset {
	string filename;
	set <T> s;

public:
	typedef typename set<T>::iterator iterator;
	typedef P persistor;

	pset(string fname) : filename(fname) { readvector(); }
	~pset() { writevector(); }
	void insert(const T& el) { s.insert(el); }
	void erase(const T el) { s.erase(el); } //element erasing
	void erase(iterator it) { s.erase(it); } //index erasing
	
	void writevector() {
		ofstream ofs(filename);
		iterator cur = s.begin();
		iterator lst = s.end();
		while (cur != lst) persistor::write_element(ofs, *cur++);
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
