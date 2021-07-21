//
// Created by Yves Boutellier on 27.11.20.
//

#ifndef EXERCISE05_PLAYERWRAPPER_H
#define EXERCISE05_PLAYERWRAPPER_H

#include "ComputerPlayer.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "EnemyPlayer.h"
#include "HumanPlayer.h"
#include "PlayerInterface.h"



template <typename Playertype>
class PlayerWrapper: public Playertype, public player{
public:
    int number;

    PlayerWrapper(int num): number(num), player(), Playertype(num){};

    /*
    PlayerWrapper(int num): number(num), player(){
        if (needNumber<Playertype>()){
            Playertype(num);
        }else{
            Playertype();
        }
    };

    /*
    bool _needNumber(ComputerPlayer<playfield>* player){
        return true;
    }

    bool _needNumber(ch::uzh::frauchiger::dominik::l4::player_frauchi<playfield>* player){
        return false;
    }

    bool _needNumber(Computerplayer<playfield>* player){
        return true;
    }

    bool _needNumber(HumanPlayer<playfield>* player){
        return true;
    }

    template <typename T>
    bool needNumber()
    {
        return true;
    }

    template<>
    bool needNumber <ch::uzh::frauchiger::dominik::l4::player_frauchi<playfield> > ()
    {
        return false;
    };

    template<>
    bool needNumber <ComputerPlayer<playfield> >()
    {
        return true;
    };
    */

    //PlayerWrapper(int num): number(num), Playertype(num), player(){};

    std::string _getName(ComputerPlayer<playfield>* player){
        return "My Computer Player";
    }

    std::string _getName(ch::uzh::frauchiger::dominik::l4::player_frauchi<playfield>* player){
        return "Dominik's Computer Player";
    }

    std::string _getName(Computerplayer<playfield>* player){
        return "Vincent's Computer Player";
    }

    std::string _getName(computerplayer<playfield>* player){
        return "Ivan's Computer Player";
    }

    std::string _getName(HumanPlayer<playfield>* player){
        return "Human Player";
    }

    virtual std::string getName(){
        return _getName(this);
    }

    virtual int play(const playfield& field) override {
        return Playertype::play(field);
    };

};

#endif //EXERCISE05_PLAYERWRAPPER_H
