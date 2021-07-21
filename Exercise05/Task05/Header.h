//
// Created by Yves Boutellier on 18.11.20.
//

#ifndef EXERCISE05_SPELLCHECKER_H
#define EXERCISE05_HEADER_H
#include <algorithm>


template <typename F, typename S>
F __merge(F first, S second, std::random_access_iterator_tag dummy){
    F _new_;
    std::merge(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(_new_));
    return _new_;
}

template <typename F, typename S>
S __merge(F first, S second, std::forward_iterator_tag dummy){
    S _new_;
    std::merge(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(_new_));
    return _new_;
}


template <typename F, typename S>
auto merge(F first, S second){
    using cat1 = typename F::iterator::iterator_category;
    auto result = __merge(first, second, cat1());
    return result;
}

#endif //EXERCISE05_SPELLCHECKER_H
