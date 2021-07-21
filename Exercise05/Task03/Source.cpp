//
// Created by Yves Boutellier on 18.11.20.
//


#include "Header.h"
using namespace std;


int main(int argc, char* argv[]) {
    myplayfield* board = new myplayfield();
    board->initialize_board();
    /*ComputerPlayer<myplayfield> p1; //Variable type 'ComputerPlayer<myplayfield>' is an abstract class
    Computerplayer<myplayfield> p2;*/ // disappears if play is not virtual
    string Player1 = "Mine";
    string Player2 = "Ivan";
    board->play_game(Player1,Player2);
}