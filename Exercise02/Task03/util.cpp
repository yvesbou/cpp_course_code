#include<iostream>
#include "util.h"
using namespace std;
int gcf(int a, int b) {
	a = abs(a);
	b = abs(b);
	int gcf = 1;
	while (a != b)
	{
		if (a > b) {
			a -= b;
		}
		else if (a == 0 || b == 0) return a;
		else
			b -= a;
	}
	//cout << "gcf:" << a;
	return a;
};
void check_char(istream& is, char ch) {
	char c; is >> c; if (c != ch) {
		is.putback(c); is.setstate(ios::badbit);
	}
};