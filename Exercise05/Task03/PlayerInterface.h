//
// Created by Yves Boutellier on 18.11.20.
//

#ifndef EXERCISE05_PLAYERINTERFACE_H
#define EXERCISE05_PLAYERINTERFACE_H

#include <iostream>
#include <string>
#include "PlayfieldInterface.h"

class player {
public:

    virtual int play(const playfield &field) = 0;
    virtual std::string getName() = 0;
    virtual ~player() {} };



#endif //EXERCISE05_PLAYERINTERFACE_H
