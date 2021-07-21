#include <complex>
#include <iostream>
#include <string>


using namespace std;

const double pi = 3.14159265358979323846;

struct Aspolar {
	enum Flag {
		DEG,
		RAD,
		GRAD,
	};

	Aspolar() {};
	template<typename C>
	string operator()( complex<C> c, Aspolar::Flag flag) {
		switch (flag) {
		case Aspolar::RAD:
			return to_string(arg(c));

		case Aspolar::DEG:
			return to_string(arg(c) / (2 * pi) * 360);

		case Aspolar::GRAD:
			return to_string(arg(c) / (2 * pi) * 400);

		}
	};
};



int main() {
	Aspolar aspolar;
	complex <double> c1(1., 1.);
	cout << c1 << " is equal to: " << aspolar(c1, Aspolar::RAD) << " rad" << endl;
	cout << c1 << " is equal to: " << aspolar(c1, Aspolar::GRAD) << " grad" << endl;
	cout << c1 << " is equal to: " << aspolar(c1, Aspolar::DEG) << " degrees" << endl;
}

