#include "Knight.h"
#include <iostream>

Knight::Knight(Player* owner, int row, int col, Board* brd) :Piece(owner, 'n', row, col, brd) {}
bool Knight::isLegalMove(int row, int col)const {
	//check if destination is within borders
	if (row >= BOARD_SIZE || col >= BOARD_SIZE || row < 0 || col < 0) {
		std::cout << "bad coordinates" << std::endl;
		return false;
	}
	//check if the destination isn't occupied with friendly piece
	if (this->getPlayer() == _brd->getBoard()[row][col].getPlayer()) {
		std::cout << "Can't overide friendly piece." << std::endl;
		return false;
	}
	//check if destination is reachable within one move
	return ((_row - 2 == row) && (_col - 1 == col)) || ((_row - 2 == row) && (_col + 1 == col)) ||
		((_row + 2 == row) && (_col - 1 == col)) || ((_row + 2 == row) && (_col + 1 == col));
}