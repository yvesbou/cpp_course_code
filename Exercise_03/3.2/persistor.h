#pragma once
#include <string>
#include <fstream>


using namespace std;

template<typename T>
class persistor {

public:
	static T read_element(ifstream& ifs) {
		T element;
		ifs >> element;
		return element;
	}
	static void write_element(ofstream& ofs, T element) {
		ofs << element;
		ofs << " ";
	}
};
template<>
class persistor<string> {

public:
	static string read_element(ifstream& ifs) {
		string element;
		getline(ifs, element);
		return element;
	}
	static void write_element(ofstream& ofs, string element) {
		ofs << element;
		ofs << endl;
	}
};