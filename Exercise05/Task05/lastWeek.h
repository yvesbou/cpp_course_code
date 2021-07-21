//
// Created by Yves Boutellier on 18.11.20.
//

#ifndef EXERCISE05_LASTWEEK_H
#define EXERCISE05_LASTWEEK_H
template <typename T, typename U>
T Merge(T first, U second){
    T _new_;
    _new_.insert(_new_.begin(), first.begin(), first.end());
    _new_.insert(_new_.end(), second.begin(), second.end());
    return _new_;
}
#endif //EXERCISE05_LASTWEEK_H
