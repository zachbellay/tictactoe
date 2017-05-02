#include "board.h"
#include <stdlib.h>
#include <string>
namespace tictactoe{
	board::board(unsigned int board_size){
		size = board_size;
		b = new std::string*[size];
		for(int i = 0; i < size; ++i){
			b[i] = new std::string[size];
			for(int j = 0; j < size; ++j){
				std::string tmp = std::to_string(((i * size) + j));
				b[i][j] = tmp;
			}
		}
	}
	
	board::~board(){
		for(int i = 0; i < size; ++i){
			delete[] b[i];
		}
		delete[] b;
		size = 0;
	}

	bool board::is_num(const std::string &s){
		std::string::const_iterator it = s.begin();
		while(it != s.end() && std::isdigit(*it)) ++it;
		return !s.empty() && it == s.end();
	}

	bool board::is_num(const std::string &s) const{
		std::string::const_iterator it = s.begin();
		while(it != s.end() && std::isdigit(*it)) ++it;
		return !s.empty() && it == s.end();
	}

	std::string board::get_item(int pos) const{
		int row = pos / size;
		int col = pos % size;
		return b[row][col];
	}
	
	std::string board::get_item(int row, int col) const{
		return b[row][col];
	}

	void board::print(){
		for(int i = 0; i < size; ++i){
			for(int j = 0; j < size; ++j){
				std::cout << b[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	
	bool board::x_win() const{
		//Horizontal Win
		for(int i = 0; i < size; ++i){
			for(int j = 0; j < size; ++j){
				std::string tmp = b[i][j];
				if(tmp.compare("X") || is_num(b[i][j]))
					break;
				return true;
			}
		}

		//Vertical Win
		for(int i = 0; i < size; ++i){
			for(int j = 0; i < size; ++j){
				std::string tmp = b[j][i];
				if(tmp.compare("X") || is_num(b[j][i]))
					break;
				return true;
			}
		}

		//Diagonal Win Top Left to Bottom Right
		for(int i = 0; i < size; ++i){
			std::string tmp = b[i][i];
			if(tmp.compare("X") || is_num(b[i][i]))
				break;
			return true;
		}

		//Diagonal Win Top Right to Bottom Left
		for(int i = 0; i < size; ++i){
			
			std::string tmp = b[i][(size-1)-i];
			if(tmp.compare("X") || is_num(b[i][(size-1)-i]))
				break;
			return true;
		}

		return false;
	}

	bool board::o_win() const{
		//Horizontal Win
		for(int i = 0; i < size; ++i){
			for(int j = 0; j < size; ++j){
				std::string tmp = b[i][j];
				if(tmp.compare("O") || is_num(b[i][j]))
					break;
				return true;
			}
		}

		//Vertical Win
		for(int i = 0; i < size; ++i){
			for(int j = 0; i < size; ++j){
				std::string tmp = b[j][i];
				if(tmp.compare("O") || is_num(b[j][i]))
					break;
				return true;
			}
		}

		//Diagonal Win Top Left to Bottom Right
		for(int i = 0; i < size; ++i){
			std::string tmp = b[i][i];
			if(tmp.compare("O") || is_num(b[i][i]))
				break;
			return true;
		}

		//Diagonal Win Top Right to Bottom Left
		for(int i = 0; i < size; ++i){
			
			std::string tmp = b[i][(size-1)-i];
			if(tmp.compare("O") || is_num(b[i][(size-1)-i]))
				break;
			return true;
		}

		return false;
	}

	bool board::insert_o(int pos){
		assert(pos < (size*size));
		int row = pos / size;
		int col = pos % size;
		if(!is_num(b[row][col])){
			return false;
		}else{
			b[row][col] = "O";
			return true;
		}
	}

	bool board::insert_o(int row, int col){
		int pos = ((row * size) + col);
		assert(pos < (size*size));
		if(!is_num(b[row][col])){
			return false;
		}else{
			b[row][col] = "O";
			return true;
		}
	}

	bool board::insert_x(int pos){
		assert(pos < (size*size));
		int row = pos / size;
		int col = pos % size;
		if(!is_num(b[row][col])){
			return false;
		}else{
			b[row][col] = "X";
			return true;
		}
	}

	bool board::insert_x(int row, int col){
		int pos = ((row * size) + col);
		assert(pos < (size*size));

		if(!is_num(b[row][col])){
			return false;
		}else{
			b[row][col] = "X";
			return true;
		}
	}

	std::ostream& operator << (std::ostream& out, const board& b){
		for(int i = 0; i < b.get_size(); ++i){	
			for(int j = 0; j < b.get_size(); ++j){
				out << b.get_item(i, j) << " ";
			}
			out << std::endl;
		}
		return out;
	}
}