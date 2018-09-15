#include "Rook.h"

Rook::Rook(Player* owner, int row, int col, Board* brd) :Piece(owner, 'r', row, col, brd) {}
bool Rook::isLegalMove(int row, int col)const {
	if (_row != row && _col != col)
		return false;
	return isWayFree(row, col);
}