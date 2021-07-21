//
// Created by Yves Boutellier on 04.11.20.
//

#ifndef EXERCISE04_FINDIF_H
#define EXERCISE04_FINDIF_H
#include <vector>
#include "Source.h"
#include "matcher.h"

#include <iostream>

template<typename Iter, typename Pred>
Iter findif(Iter begin, Iter beyond, Pred&& pred) {

    while (begin!=beyond) { if (pred(*begin)) break; ++begin;}
    return begin; }



#endif //EXERCISE04_FINDIF_H
