#include "King.h"

King::King(Player* owner, int row, int col, Board* brd) :Piece(owner, 'k', row, col, brd) {
	owner->setKing(this);
}
bool King::isLegalMove (int row,int col)const{
	//check if the destination isn't neighbor to current location - if destination isn't reachable
	if (row > _row + 1 || row < _row - 1 || col > _col + 1 || col < _col - 1)
		return false;
	return true;

}
bool King::isChess(){
	Piece** brd = _brd->getBoard();

	for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
		//skip NULL places on board and friendly pieces
		if (brd[i]->getSign() == '#' ||
			getPlayer()->isWhite() == brd[i]->getPlayer()->isWhite())
			continue;
		//check if rival piece can eat this king
		if (brd[i]->isLegalMove(this->_row,this->_col))
			return true;
	}
	return false;
}