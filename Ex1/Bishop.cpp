#include "Bishop.h"

Bishop::Bishop(Player* owner, int row, int col, Board* brd):Piece(owner,'b',row,col,brd) {}
bool Bishop::isReachable(int dstRow,int dstCol)const {
	if (this->_row == dstRow || this->_col == dstCol)
		return false;
	if (_col < dstCol) {
		//_col + X = dstCol
		if (_row < dstRow)
			//_row + X = dstRow
			return _col - _row == dstCol - dstRow;
		else
			//_row - X = dstRow
			return _col + _row == dstCol + dstRow;
	}else {
		//_col -X = dstCol
		if (_row < dstRow)
			//_row + X = dstRow
			return _col + _row == dstCol + dstRow;
		else
			//_row - X = dstRow
			return _col - _row == dstCol - dstRow;
	}
}