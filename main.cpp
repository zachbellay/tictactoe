#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "board.h"
using namespace std;
int main(){
	
	int board_size;
	bool x_turn = true;

	cout << "2 Player Tic Tac Toe:" << endl;
	cout << "How large should the board be? (Enter a whole number): ";
	cin >> board_size;
	tictactoe::board b(board_size);
	while(!b.x_win() && !b.o_win()){
		cout << string(50, '\n');
		cout << b;
		if(x_turn){
			bool inserted = false;
			while(!inserted){
				int pos;
				cout << "X, enter the position you want to insert at: ";
				cin >> pos;
				inserted = b.x_insert(pos);
				x_turn = false;
			}	
		}else{
			bool inserted = false;
			while(!inserted){
				int pos;
				cout << "O, enter the position you want to insert at: ";
				cin >> pos;
				inserted = b.o_insert(pos);
				x_turn = true;
			}
		}	
		cout << b;
		if(b.x_win()){
			cout << "X has won!" << endl;
		}else{
			cout << "O has won!" << endl;
		}
	}
	return EXIT_SUCCESS;
}