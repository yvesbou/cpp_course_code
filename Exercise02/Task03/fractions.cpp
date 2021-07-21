#include "fractions.h"
#include "util.h"
using namespace std;

istream& operator>> (istream& is, fraction& right) {
	fraction g;
	check_char(is, '(');  is >> g.c;
	check_char(is, '/');  is >> g.d;
	check_char(is, ')'); if (is) right = g;
	return is;
};
ostream& operator<<(ostream& os, fraction& right) {
	return os << '(' << right.c << '/' << right.d << ')';
}
bool operator>(fraction left, fraction right) {
	return((float)left.c / (float)left.d > (float)right.c / (float)right.d);
}
bool operator<(fraction left, fraction right) {
	return((float)left.c / (float)left.d < (float)right.c / (float)right.d);
}
fraction min(fraction left, fraction right) {
	if (left < right) {
		return left;
	}
	else { return right; }
}
