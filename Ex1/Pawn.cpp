#include "Pawn.h"

Pawn::Pawn(Player* owner, int row, int col, Board* brd) :Piece(owner, 'p', row, col, brd) {}
bool Pawn::isReachable(int row, int col)const {
	//check if the is the speicial first move
	if (row == _row + 2 && this->_row == 1 && !this->getPlayer()->isWhite())
		return true;
	if (row == _row - 2 && this->_row == BOARD_SIZE - 2 && this->getPlayer()->isWhite()) {
		return true;
	}
	//check 1 step ahead ((Piece(*)[8]) brd[0],8)
	Piece*** brd = _brd->getBoard();
	if ((!this->getPlayer()->isWhite() && _row == row - 1) || (this->getPlayer()->isWhite() && _row == row + 1)) 
		if (brd[row][col]->getSign() == '#')
			return true;
	//check eating option
	if (row == _row + 1 && (col == _col + 1 || col == _col - 1))
		return this->getPlayer()->isWhite() != (_brd->getBoard())[row][col]->getPlayer()->isWhite();
	return false;
}