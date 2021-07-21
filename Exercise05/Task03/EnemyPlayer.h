//
// Created by Yves Boutellier on 18.11.20.
//

#ifndef EXERCISE05_ENEMYPLAYER_H
#define EXERCISE05_ENEMYPLAYER_H
#include <string>
#include <iostream>

using namespace std;

template<typename F>
class Computerplayer{
public:
    char player;
    char opponent;
    int none = 0;
    double gamma = 0.8;
    const static int width = 7;
    const static int height = 6;

    char rep[width][height];
    Computerplayer(int tag):player(tag){
        // todo: show
        if (player == 1) { opponent = 2; }
        else { opponent = 1; }
    }
    char opposite(char playertype) {
        if (playertype == player) {
            return opponent;
        }
        else { return player; }
    }

    void set_player(int tag) {

        if (tag == 1) { player = 1; opponent = 2; }
        else { player = 2; opponent = 1; }
    }
    //virtual int play(const playfield &field)
    int play(const F& field) {
        std::cout << "My Enemy's turn" << std::endl;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                rep[i][j] = field.stoneat(i, j);
            }
        }
        return get_move();
    }
    int stoneat(int x, int y) const{
        return rep[x][y];
    }
    int get_move() {

        double max_val=-100000;
        int max;
        double value;
        int xi; int yi;
        //cout << player << opposite(player) << opponent<< endl;
        max = rand() % 7;
        for (xi = 0; xi < width; xi++) {
            yi = gravity(xi);
            if (is_empty(xi, yi)) {
                insert_stone(xi, yi,player);
                value = goodness(xi, yi, player,7)*gamma;
                //cout << "goodness of" << xi << "is:" << value << endl;
                if (value > max_val) {
                    max_val = value;
                    max = xi;
                }
                remove_stone(xi, yi);
            }
        }
        return max;
    };
    double goodness(int x, int y, char playertype,int depth) {
        double max = -10000.0;
        double avg=0.0;
        int count=0;
        double value;
        int xi; int yi;
        //cout << "recursion depth: " << depth <<"playertype:" <<playertype << "consecutives" << max_consecutive(x,y,playertype)<< endl;
        if (check_consecutive(x, y, playertype, 4)) {
            //cout << "win possibility found for:" << playertype << endl;
            return 128; }
        if (depth == 0) { return 0; }
        max = -1000;
        for (xi = 0; xi < width; xi++) {
            yi = gravity(xi);
            if (is_empty(xi, yi)) {
                insert_stone(xi, yi,opposite( playertype));
                value = -goodness(xi,yi,opposite(playertype),depth-1)*gamma;
                remove_stone(xi, yi);
                count++;
                avg += value;
                if (value > max) {
                    max = value;
                }
            }
        }
        avg = avg / count;
        return avg;
    }


    bool is_empty(int x, int y) {
        if (stoneat(x, y) != none) {
            //cout << "the Input position is not empty" << endl;
            return false;
        }
        else {
            return true;
        }
    }
    int gravity(int x) {
        int y = 0;
        for (int yi = y; yi < ((int)height) - 1; yi++) {
            if (stoneat(x, yi + 1) == none) {
                y++;
            }
            else break;
        }
        return y;
    }
    void insert_stone(int& x, int& y,  char playertype) {
        rep[x][y] = playertype;
    }
    void remove_stone(int& x, int& y) {
        rep[x][y] = none;
    }
    bool check_consecutive(int x, int y, const char playertype, int length) {//TODO implelemnt check
        //horizontal check
        int xi; int yi;
        int counter = 0;
        for (xi = 0; xi <= ((int)width) - 1; xi++) {
            if (stoneat(xi, y) == playertype) { counter++; }
            else counter = 0;
            if (counter >= length) { return true; }
        }
        //cout << counter;
        counter = 0;
        //vertical check
        for (yi = 0; yi <= ((int)height) - 1; yi++) {
            if (stoneat(x, yi) == playertype) { counter++; }
            else counter = 0;
            if (counter >= length) { return true; }
        }
        //scout << counter;
        counter = 0;
        // diagonal down right check;
        xi = x; yi = y;
        for (;;) {
            if ((xi > ((int)width) - 1) || (yi > ((int)height) - 1)) break;
            if (stoneat(xi, yi) == playertype) counter++;
            else break;
            if (counter >= length) { return true; }
            xi++; yi++;

        }
        counter--;
        //diagonal up left check
        xi = x; yi = y;
        for (;;) {
            if ((xi < 0) || (yi < 0)) break;
            if (stoneat(xi, yi) == playertype) counter++;
            else break;
            if (counter >= length) { return true; }
            xi--; yi--;
        }
        //cout << counter;
        counter = 0;
        //diagonal up right check
        xi = x; yi = y;
        for (;;) {
            if ((xi > ((int)width) - 1) || (yi < 0)) break;
            if (stoneat(xi, yi) == playertype) counter++;
            else break;
            if (counter >= length) { return true; }
            xi++; yi--;
        }

        counter--;
        //diagonal down left check
        xi = x, yi = y;
        for (;;) {
            if ((xi < 0) || (yi > ((int)height) - 1)) break;
            if (stoneat(xi, yi) == playertype) counter++;
            else break;
            if (counter >= length) { return true; }
            xi--; yi++;
        }
        return false;

    }




    int max_consecutive(int x, int y, const char playertype) {//TODO implelemnt check
        //horizontal check
        int max = 0;
        int xi; int yi;
        int counter = 0;
        for (xi = 0; xi <= ((int)width) - 1; xi++) {
            if (stoneat(xi, y) == playertype) { counter++; }
            else counter = 0;
            if (counter > max) { max = counter; }
        }
        //cout << counter;
        counter = 0;
        //vertical check
        for (yi = 0; yi <= ((int)height) - 1; yi++) {
            if (stoneat(x, yi) == playertype) { counter++; }
            else counter = 0;
            if (counter > max) { max = counter; }
        }
        //scout << counter;
        counter = 0;
        // diagonal down right check;
        xi = x; yi = y;
        for (;;) {
            if ((xi > ((int)width) - 1) || (yi > ((int)height) - 1)) break;
            if (stoneat(xi, yi) == playertype) counter++;
            else break;
            if (counter > max) { max = counter; }
            xi++; yi++;

        }
        counter--;
        //diagonal up left check
        xi = x; yi = y;
        for (;;) {
            if ((xi < 0) || (yi < 0)) break;
            if (stoneat(xi, yi) == playertype) counter++;
            else break;
            if (counter > max) { max = counter; }
            xi--; yi--;
        }
        //cout << counter;
        counter = 0;
        //diagonal up right check
        xi = x; yi = y;
        for (;;) {
            if ((xi > ((int)width) - 1) || (yi < 0)) break;
            if (stoneat(xi, yi) == playertype) counter++;
            else break;
            if (counter > max) { max = counter; }
            xi++; yi--;
        }

        counter--;
        //diagonal down left check
        xi = x, yi = y;
        for (;;) {
            if ((xi < 0) || (yi > ((int)height) - 1)) break;
            if (stoneat(xi, yi) == playertype) counter++;
            else break;
            if (counter > max) { max = counter; }
            xi--; yi++;
        }
        return max;

    }
};
#endif //EXERCISE05_ENEMYPLAYER_H
