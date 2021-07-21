
#include <vector>
#include<iostream>
#include<fstream>

using namespace std;
template<typename T>
struct pvector {
	string filename;
	vector<T> v;
	typename vector<T>::iterator cur = v.begin(), lst = v.end();
public:
	pvector(string fname) : filename(fname) { readvector(); }
	~pvector() { writevector(); }
	void push_back(const T& el) { v.push_back(el); }
	void pop_back() { v.pop_back(); }
	void readvector() {
		ifstream ifs(filename);
		for (;;) {
			T x; ifs >> x; if (!ifs.good()) break;
			v.push_back(x);
		}
	}
	void writevector() {
		ofstream ofs(filename);
		typename vector<T>::iterator fst = v.begin(), lst = v.end();
		while (fst != lst) ofs << *fst++ << endl;
	}
	T operator[] (int index) {
		return v[index];
	}
	friend ostream& operator<< (ostream& os, pvector& pout) {
		pout.cur = pout.v.begin();
		pout.lst = pout.v.end();
		while (pout.cur != pout.lst) os << *pout.cur++ << endl;
		return(os);
	}

    void check_char(istream& is, char ch) {
        char c; is >> c; if (c != ch) {
            is.putback(c); is.setstate(ios::badbit);
        }
    };
};


