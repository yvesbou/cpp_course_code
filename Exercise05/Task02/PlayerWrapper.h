//
// Created by Yves Boutellier on 26.11.20.
//

#ifndef EXERCISE05_PLAYERWRAPPER_H
#define EXERCISE05_PLAYERWRAPPER_H

#include "ComputerPlayer.h"
#include "Enemy2.h"
#include "EnemyPlayer.h"
#include "HumanPlayer.h"
#include "PlayerInterface.h"


template <typename Playertype>
class PlayerWrapper: public Playertype, public player{
public:
    PlayerWrapper() {}

    int number;
    PlayerWrapper(int num): number(num), Playertype(num), player(){};

    std::string _getName(ComputerPlayer<playfield>* player){
        return "My Computer Player";
    }

    std::string _getName(ch::uzh::frauchiger::dominik::l4::player_frauchi<playfield>* player){
        return "Dominik's Computer Player";
    }

    std::string _getName(Computerplayer<playfield>* player){
        return "Vincent's Computer Player";
    }

    std::string _getName(ConsolePlayer<playfield>* player){
        return "Human Player";
    }

    virtual std::string getName(){
        return _getName(this);
    }

    virtual int play(const playfield& field) override {
        //return this->play(field);
        return Playertype::play(field);
    };

};

#endif //EXERCISE05_PLAYERWRAPPER_H
