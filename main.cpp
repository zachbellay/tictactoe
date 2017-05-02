#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "board.h"
int main(){
	tictactoe::board b(5);
	//b.insert_o(4);
	// b.insert_o(9);
	// b.insert_o(12);
	// b.insert_o(16);
	b.insert_o(20);
	std::cout << b;
	std::cout << b.o_win() << std::endl;
	return EXIT_SUCCESS;
}