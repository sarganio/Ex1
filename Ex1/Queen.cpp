#include "Queen.h"

Queen::Queen(Player* owner, int row, int col, Board* brd) :Piece(owner, 'q', row, col, brd) {}
bool Queen::isReachable(int row,int col)const {
	return true;
}