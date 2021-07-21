#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include "fractions.h"
#include "RPN.h"


extern int gcf(int a, int b);

using namespace std;
int main(int argc, char* argv[]) {
	RPN<fraction>("fraction.txt");

}