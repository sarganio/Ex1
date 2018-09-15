#include "Queen.h"

Queen::Queen(Player* owner, int row, int col, Board* brd) :Piece(owner, 'q', row, col, brd) {}
bool Queen::isLegalMove(int row,int col)const {
	return isWayFree(row, col);
}