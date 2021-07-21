#ifndef _Frac_H
#define _Frac_H
#include "util.h"
#include <iostream>
using namespace std;
struct fraction {
	int c;
	int d;
public:
	fraction() {
	};
	fraction(int counter, int denominator) {
		c = counter;
		d = denominator;
	};
	fraction operator+(fraction right) {
		//cout << ",c: " << c << ",d: " << d << ",right.c: " << right.c << ",right.d: " << right.d;
		int new_c = c * right.d + right.c * d; int new_d = d * right.d;
		int shorten = gcf(new_c, new_d);
		new_c = new_c / shorten; new_d = new_d / shorten;
		//cout << "after:" << ",c: " << c << ",d: " << d << ",right.c: " << right.c << ",right.d: " << right.d;
		return (fraction(new_c, new_d));
	};
	fraction operator-(fraction right) {
		int new_c = c * right.d - right.c * d; int new_d = d * right.d; //expand the fractions and subtract
		int shorten = gcf(new_c, new_d);
		new_c /= shorten; new_d /= shorten;  // shorten the resulting fraction
		return (fraction(new_c, new_d));
	};
	fraction operator*(fraction right) {
		int new_c = c * right.c;
		int new_d = d * right.d;
		int shorten = gcf(new_c, new_d);
		new_c /= shorten; new_d /= shorten;
		return (fraction(new_c, new_d));
	};
	fraction operator/(fraction right) {
		return (this ->  operator* (fraction(right.d, right.c)));
	}
	friend ostream& operator<< (ostream& os, fraction& right);
	friend istream& operator>> (istream& is, fraction& right);
	friend bool operator<(fraction left, fraction right);
	friend bool operator>(fraction left, fraction right);
	fraction min(fraction left, fraction right);
};
void check_char(istream& is, char ch);

extern bool operator<(fraction left, fraction right);
extern bool operator>(fraction left, fraction right);

extern ostream& operator<<(ostream& os, fraction& right);
extern void check_char(istream& is, char ch);

extern istream& operator>> (istream& is, fraction& right);
#endif


