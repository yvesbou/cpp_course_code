//
// Created by Yves Boutellier on 18.11.20.
//

#ifndef EXERCISE05_PLAYERINTERFACE_H
#define EXERCISE05_PLAYERINTERFACE_H

#include <iostream>
#include "PlayfieldInterface.h"
#include <string>

class player {
public:
    virtual int play(const playfield &field) = 0;
    virtual ~player() {}
    virtual std::string getName() = 0;
};



#endif //EXERCISE05_PLAYERINTERFACE_H
