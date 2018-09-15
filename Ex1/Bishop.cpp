#include "Bishop.h"

Bishop::Bishop(Player* owner, int row, int col, Board* brd):Piece(owner,'b',row,col,brd) {}
bool Bishop::isLegalMove(int row, int col) const {
	Piece** brd = _brd->getBoard();
	//reachable + free way + non friendly piece at destination =>true , otherwise =>false
	return isReachable(row, col) && isWayFree(row, col) && brd[row][col].getPlayer()->isWhite() !=this->getPlayer()->isWhite();
}
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