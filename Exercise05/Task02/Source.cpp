//
// Created by Yves Boutellier on 18.11.20.
//


#include "Header.h"
using namespace std;


int main(int argc, char* argv[]) {
    myplayfield* board = new myplayfield();
    board->initialize_board();
    board->play_game();
}