#include "Bishop.h"

Bishop::Bishop(Player* owner, int row, int col, Board* brd):Piece(owner,'b',row,col,brd) {}
bool Bishop::isLegalMove(int row, int col) const {
	if (this->_row == row || this->_col == col)
		return false;
	return this->isWayFree(row, col);
}