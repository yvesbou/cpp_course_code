//
// Created by Yves Boutellier on 18.11.20.
//

#ifndef EXERCISE05_HEADER_H
#define EXERCISE05_HEADER_H
#include <iostream>
#include <sstream>
#include <string>
#include "PlayerWrapper.h"


//todo: show
class myplayfield : public playfield {
public:
    // the size of the field
    //const static int width = 7;
    //const static int height = 6;
    int width_int = 7;
    int height_int = 6;
    // these elements are used to indicate whether a given position
    // in the playing field is taken by a given player
    const static char none = 0;
    //const static char player1 = 1;
    //const static char player2 = 2;

    // the internal representation of the field
    char rep[playfield::width][playfield::height];
    // return the stone (none/player1/player2) at position(x, y)
    // 0 <= x <= width
    // 0 <= y <= height
    // stoneat(0, 0) ................ top left
    // stoneat(width-1, height-1) ... bottom right
    // if we insert a stone in a new game in column i,
    // it lands at (i, height-1)
    // implementation may be changed, interface not
    void initialize_board() {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                rep[x][y] = none;
            }
        }
    }
    void const print_board() {

        std::cout << std::endl;
        std::cout << "    |";
        for (int x = 0; x < width; x++) {
            std::cout << "[" << x << "]";
        };
        std::cout << '|' << std::endl;


        for (int y = 0; y < height; y++) {
            std::cout << "[" << y << "] |";
            for (int x = 0; x < width; x++) {
                if (stoneat(x,y) == none){
                    std::cout << "[ ]";
                }else{
                    std::cout << "[" << stoneat(x, y) << "]";
                }

            }
            std::cout << '|' <<std::endl;
        }

    }
    //todo: show
    void play_game() {
        print_board();
        // computer players receive template argument playfield interface
        PlayerWrapper<ComputerPlayer<playfield> > p1(1);
        //PlayerWrapper<Computerplayer<playfield> > p2(2);
        PlayerWrapper<ch::uzh::frauchiger::dominik::l4::player_frauchi<playfield> > p2;


        bool finished = false;
        for(;;) {
            //turn of player1
            int x, y;
            for (;;) {
                std::cout << p1.getName() << "'s turn" << " with number: " << player1 << std::endl;
                x = p1.play(*this);
                if (!input_valid(x)){continue;}
                y = gravity(x);
                if (!is_Empty(x,y)){continue;}


                insert_stone(x,y,player1);
                break;
            }
            print_board();
            finished = check_winner(x,y,player1);
            if (finished) {
                std::cout << p1.getName() << " Won" << std::endl;
                return;
            }
            //turn of computerPlayer
            for (;;) {
                std::cout << p2.getName() << "'s turn"  << " with number: " << player2 << std::endl;
                x = p2.play(*this);
                if (!input_valid(x)){continue;}
                y = gravity(x);
                if (!is_Empty(x,y)){continue;}

                insert_stone(x,y,player2);
                break;
            }
            print_board();
            finished = check_winner(x,y,player2);
            if (finished) {
                std::cout << p2.getName() << " Won" << std::endl;
                return;
            }
        }
    }

    bool check_winner(int x, int y, const char player) {
        //horizontal check
        int xi; int yi;
        int counter = 0;
        for (xi = 0; xi <= ((int)width)-1 ;xi++ ) {
            if (stoneat(xi, y) == player ){ counter++; }
            else counter =0;
            if (counter >= 4) { return true; }
        }
        //std::cout << counter;
        counter = 0;
        //vertical check
        for (yi = 0; yi <= ((int)height)-1; yi ++) {
            if (stoneat(x, yi) == player) { counter++; }
            else counter = 0;
            if (counter >= 4) { return true; }
        }
        //std::cout << counter;
        counter = 0;
        // diagonal down right check;
        xi = x; yi = y;
        for (;;) {
            if ( (xi > ((int)width-1) ) || (yi > ((int)height-1) ) ) break;
            if (stoneat(xi, yi) == player) counter++;
            else break;
            if (counter >= 4) { return true; }
            xi++; yi++;

        }
        //std::cout << counter;
        counter--;
        //diagonal up left check
        xi = x; yi = y;
        for (;;) {
            if ((xi < 0) || (yi < 0)) break;
            if (stoneat(xi, yi) == player ) counter++;
            else break;
            if (counter >= 4) { return true; }
            xi--; yi--;
        }

        //std::cout << counter;
        counter = 0;
        //diagonal up right check
        xi = x; yi = y;
        for (;;) {
            if ((xi > ((int)width-1) ) || (yi < 0)) break;
            if (stoneat(xi, yi) == player) counter++;
            else break;
            if (counter >= 4) { return true; }
            xi++; yi--;
        }
        //std::cout << counter;
        counter--;
        //diagonal down left check
        xi = x, yi = y;
        for (;;) {
            if ((xi <  0) || (yi > ((int)height-1))) break;
            if (stoneat(xi, yi) == player ) counter++;
            else break;
            if (counter >= 4) { return true; }
            xi--; yi++;
        }

        //std::cout << counter;
        return false;

    }

    bool input_valid(int x) {
        if ((x < 0) ||  (x > width-1) ) {
            return false;
        }
        else return true;
    }

    const int gravity(int x) {
        int y = 0;
        for (int yi =y; yi < (height-1); yi++) {
            if (stoneat(x, yi + 1) == none) {
                y++;}
            else break;}
        return y;}

    bool is_Empty(int x, int y){
        if (stoneat(x,y) != none) {
            std::cout << "the Input position is not empty"<< std::endl;
            return false;}
        else{
            return true;
        }}

    void insert_stone(int x, int y, const char player) {
        rep[x][y] = player;}


    virtual int stoneat(int x, int y) const override {
        return rep[x][y];
    }
};

#endif //EXERCISE05_SPELLCHECKER_H
