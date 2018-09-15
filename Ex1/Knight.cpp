#include "Knight.h"
#include <iostream>

Knight::Knight(Player* owner, int row, int col, Board* brd) :Piece(owner, 'n', row, col, brd) {}
bool Knight::isReachable(int row, int col)const {
	//check if destination is reachable within one move
	return ((_row - 2 == row) && (_col - 1 == col)) || ((_row - 2 == row) && (_col + 1 == col)) ||
		((_row + 2 == row) && (_col - 1 == col)) || ((_row + 2 == row) && (_col + 1 == col));
}