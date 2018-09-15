#include "King.h"

King::King(Player* owner, int row, int col, Board* brd) :Piece(owner, 'k', row, col, brd) {}

bool King::isChess(){
	Piece** brd = _brd->getBoard();

	for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
		//skip NULL places on board and friendly pieces
		if (brd[i / BOARD_SIZE][i%BOARD_SIZE].getSign() == '#' ||
			getPlayer()->isWhite() == brd[i/BOARD_SIZE][i%BOARD_SIZE].getPlayer()->isWhite())
			continue;
		//check if rival piece can eat this king
		if (brd[i / BOARD_SIZE][i&BOARD_SIZE].isLegalMove(this->_row,this->_col))
			return true;
	}
	return false;
}