

#include<iostream>
#include<string>

#include"pset.h"
#include"pvector.h"

using namespace std;


int main(int argc, char* argv[]) {

	//********************** VECTOR ****************
	/*
	//type int 
	pvector<int> pint = pvector<int>("int.txt");
	cout << pint << endl;
	//pint.pop_back();
	pint.push_back(5);
	cout << pint << endl;
	//type string
	pvector<string> pstring = pvector<string>("string.txt");
	cout << pstring << endl;
	//pstring.pop_back();
	pstring.push_back("herd of sheeps");
	cout << pstring << endl;
	*/

	//******************** SET *********************
	
	//type int 
	pset<int> pset_int = pset<int>("int.txt");
	cout << pset_int << endl;
	//pint.pop_back();

	pset_int.insert(5);
	//pset_int.insert(6);

	cout << pset_int << endl;

	//type string
	pset<string> pset_string = pset<string>("string.txt");
	cout << pset_string << endl;

	//pset_string.insert("herd of sheep");
	pset_string.insert("foo bar");

	cout << pset_string << endl;
	
	
	
}