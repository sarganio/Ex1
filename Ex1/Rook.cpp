#include "Rook.h"

Rook::Rook(Player* owner, int row, int col, Board* brd) :Piece(owner, 'r', row, col, brd) {}
bool Rook::isLegalMove(int row, int col)const {
	return _col == col || _row == row;
}