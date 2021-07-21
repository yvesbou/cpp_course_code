//
// Created by Yves Boutellier on 04.11.20.
//

#include "Source.h"
#include "Findif.h"
#include <iostream>


int main() {
    int n = 1e7;
    std::vector<int> v(n);

    //ascending
    for (int i =0; i < n; i++){
        v[i] = i;
    }

    /* RANDOM
    srand((unsigned)time(NULL));
    for (int i =0; i < n; i++){
        int b = rand() % n + 1;
        v[i] = b;}*/

    Iterator <std::vector<int>> it(v);

    int *u;
    auto start_time = std::chrono::high_resolution_clock::now();
    u = findif(it.begin(), it.beyond(), [n](int value) { return value == n-1; });
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time-start_time).count();

    std::cout << "the last number: "<< *u << " found. "<< "It took: "<< duration << "µs" << std::endl;

}
