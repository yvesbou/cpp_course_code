#include "Header.h"
using namespace std;


int main(int argc, char* argv[]) {
	playfield* board = new playfield();
	board->initialize_board();
	board->play_game();
}