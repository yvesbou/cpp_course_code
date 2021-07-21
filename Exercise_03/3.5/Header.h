#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "ComputerPlayer.h"
#include "Enemy.h"

template <typename F>
struct ConsolePlayer {
    ConsolePlayer(int i): number(i){};
    int number;
    void set_number(int tag){
        number = tag;
    }

    int play(F &field){
        int x = 0;
        std::string line;

        std::cout << "input your next move Player " << number << std::endl;
        std::cin >> x;
        return x;
    }
};

struct playfield {

	// the size of the field
	const static int width = 7;
	const static int height = 6;
	int width_int = 7;
	int height_int = 6;
	// these elements are used to indicate whether a given position
	// in the playing field is taken by a given player
	const static char none = 0;
	const static char player1 = 1;
	const static char player2 = 2;

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
	void play_game() {
		print_board();
		ComputerPlayer<playfield> p1(1);
		Computerplayer<playfield> p2(2);

		bool finished = false;
		for(;;) {
			//turn of player1
			int x, y;
			for (;;) {

				x = p1.play(*this);
				std::cout << x << std::endl;
                if (!input_valid(x)){continue;}
                y = gravity(x);
                if (!is_Empty(x,y)){continue;}


				insert_stone(x, y,player1);
				break;
			}
			print_board();
			finished = check_winner(x,y,player1);
			if (finished) {
				std::cout <<"Player 1 Won" << std::endl;
				return;
			}
			//turn of computerPlayer
			for (;;) {
                x = p2.play(*this);
                if (!input_valid(x)){continue;}
                y = gravity(x);
                if (!is_Empty(x,y)){continue;}

                insert_stone(x, y,player2);
                break;
			}
			print_board();
			finished = check_winner(x,y,player2);
			if (finished) {
				std::cout << "Player 2 Won" << std::endl;
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


	int stoneat(int x, int y) const {
		return rep[x][y]; 
	}
};
