//
// Created by Yves Boutellier on 05.11.20.
//

#ifndef EXERCISE04_VECTOR_H
#define EXERCISE04_VECTOR_H
#include <vector>
template <typename T>
class Vector{
private:
    int len;
public:
    Vector(int n){
        //typedef typename std::vector<T>::iterator::value_type value_type;
        using value_type = typename std::vector<T>::iterator::value_type;
        len = n;
        std::vector<T> vec(n);
        srand((unsigned)time(NULL));

        for (int i =0; i < n; i++){
            int b = rand() % n + 1;
            vec[i] = b;
    }
};
};

#endif //EXERCISE04_VECTOR_H
