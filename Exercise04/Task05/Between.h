//
// Created by Yves Boutellier on 06.11.20.
//

#ifndef EXERCISE04_BETWEEN_H
#define EXERCISE04_BETWEEN_H
#include <iterator>


template <typename In>
bool __between(In first, In last, In btwn, std::forward_iterator_tag dummy) {
    bool found = false;
    while (first != last){
        if (first == btwn){
            found = true;
        }
        ++first;
    }
    return found;
}

template <typename Ran>
bool __between(Ran first, Ran last, Ran btw, std::random_access_iterator_tag dummy){
    if (first < btw && btw < last){
        return true;
    }
    else{
        return false;
    }
}

template <class I> inline
bool between(I first, I last, I btwn){
    typedef typename I::iterator_category cat;
    return __between(first, last, btwn, cat());
}

#endif //EXERCISE04_BETWEEN_H
