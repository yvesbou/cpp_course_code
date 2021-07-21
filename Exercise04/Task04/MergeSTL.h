//
// Created by Yves Boutellier on 06.11.20.
//

#ifndef EXERCISE04_MERGESTL_H
#define EXERCISE04_MERGESTL_H

template <typename T, typename U>
T merge(T first, U second){
    T _new_;
    _new_.insert(_new_.begin(), first.begin(), first.end());
    _new_.insert(_new_.end(), second.begin(), second.end());
    return _new_;
}


#endif //EXERCISE04_MERGESTL_H
