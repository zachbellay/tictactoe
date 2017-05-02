#ifndef BOARD_H
#define BOARD_H
#include <cstdio>
#include <iostream>
#include <string>
#include <cassert>
namespace tictactoe{
	class board{
		//Helper Functions
		bool is_num(const std::string &s);
		bool is_num(const std::string &s) const;
	public: 
		//Constructor
		board(unsigned int board_size = 3);
		~board();

		//Constant Member Functions
		std::string get_item(int pos) const;
		std::string get_item(int row, int col) const;
		void print();
		size_t get_size() const {return size;}
		bool x_win() const;
		bool o_win() const;

		//Modification Member Functions
		bool insert_o(int pos);
		bool insert_o(int row, int col);
		bool insert_x(int pos);
		bool insert_x(int row, int col);


	private:
		std::string **b;
		size_t size;
	};

	std::ostream& operator << (std::ostream& out, const board& b);
}
#endif