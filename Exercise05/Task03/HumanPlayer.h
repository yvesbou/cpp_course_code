//
// Created by Yves Boutellier on 27.11.20.
//

#ifndef EXERCISE05_HUMANPLAYER_H
#define EXERCISE05_HUMANPLAYER_H
#include "PlayerInterface.h"
template <typename F>
struct HumanPlayer{

    HumanPlayer();

    HumanPlayer(int i) {
        set_number(i);
    };
    ~HumanPlayer(){};
    int number;
    void set_number(int tag){
        number = tag;
    }

    int play(const F &field) {
        int x = 0;
        std::string line;

        std::cout << "input your next move Player " << number << std::endl;
        std::cin >> x;
        return x;
    }
};
#endif //EXERCISE05_HUMANPLAYER_H
