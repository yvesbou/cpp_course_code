//
// Created by Yves Boutellier on 27.10.20.
//

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    srand((unsigned) time(0));
    int randomNumber;
    for (int index = 0; index < 10; index++) {
        randomNumber = (rand() % 6) + 1;
        cout << randomNumber << endl;
    }
}


