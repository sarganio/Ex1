#include "Board.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "NullPiece.h"
#include <iostream>

Board::Board(Player* white,Player* black){
	//initialize class parameters
	this->_lastDstCol = -1;
	this->_lastDstRow = -1;
	this->_lastSrcCol = -1;
	this->_lastSrcRow = -1;
	this->_lastPiece = NULL;

	//create pieces and put on board
	for (int i = 0; i < 2; i++) {
		int row = i % 2 == 0 ? 0 : BOARD_SIZE - 1;
		_brd[row][0] = new Rook(i % 2 == 0 ? black : white, row, 0, this);
		_brd[row][1] = new Knight(i % 2 == 0 ? black : white, row, 1, this);
		_brd[row][2] = new Bishop(i % 2 == 0 ? black : white, row, 2, this);
		//_brd[row][i % 2 == 0 ? 4 : 3] = new Queen(i % 2 == 0 ? black : white, row, [i % 2 == 0 ? 4 : 3, this);
		_brd[row][i % 2 == 0 ? 3 : 4] = new King(i % 2 == 0 ? black : white, row, i % 2 == 0 ? 3 : 4, this);
		_brd[row][5] = new Bishop(i % 2 == 0 ? black : white, row, 5, this);
		_brd[row][6] = new Knight(i % 2 == 0 ? black : white, row, 6, this);
		_brd[row][7] = new Rook(i % 2 == 0 ? black : white, row, 7, this);
		
		for (int j = 0; j < BOARD_SIZE; j++) {}
			//_brd[i % 2 == 0 ? 1 : BOARD_SIZE - 2][j] = new Pawn(i % 2 == 0 ? black : white, i % 2 == 0 ? 1 : BOARD_SIZE - 2, j, this);

	}
	//create and place the NullPieces at empty places
	for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++)
		if (_brd[i / BOARD_SIZE][i%BOARD_SIZE] == NULL)
			_brd[i / BOARD_SIZE][i%BOARD_SIZE] = new NullPiece(i / BOARD_SIZE, i%BOARD_SIZE);
}
void Board::print()const {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
			std::cout << "	" << _brd[i][j]->getSign() << " ";
		std::cout << endl;
	}
}
void Board::getString(char* res)const {
	for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++)
		res[i] = _brd[i / BOARD_SIZE][i%BOARD_SIZE]->getSign();
}
bool Board::isPieceOfPlayer(int row, int col, Player* isOwner) const{
	if (_brd[row][col]->getPlayer() == NULL)
		return false;
	return _brd[row][col]->getPlayer()->isWhite() == isOwner->isWhite();
}
bool Board::tryMove(int srcRow, int srcCol, int dstRow, int dstCol) const {
	return _brd[srcRow][srcCol]->isLegalMove(dstRow, dstCol);
}
Piece** Board::getBoard()const {
	return (Piece**)_brd;
}
void Board::Move(int srcRow, int srcCol, int dstRow, int dstCol) {
	//remember new last piece
	if(_lastPiece)
		if (_lastPiece->getSign() != '#')
			delete _lastPiece;
	_lastPiece = _brd[dstRow][dstCol];
	//make move
	_brd[dstRow][dstCol] = _brd[srcRow][srcCol];
	_brd[dstRow][dstCol]->setPosition(dstRow, dstCol);
	_brd[srcRow][srcCol] = new NullPiece(srcRow,srcCol);
	//remember last move
	_lastDstCol = dstCol;
	_lastDstRow = dstRow;
	_lastSrcRow = srcRow;
	_lastSrcCol = srcCol;
}
void Board::undoLastMove() {
	_brd[_lastSrcRow][_lastSrcCol] = _brd[_lastDstRow][_lastDstCol];
	_brd[_lastSrcRow][_lastSrcCol]->setPosition(_lastSrcRow, _lastSrcCol);
	_brd[_lastDstRow][_lastDstCol] = _lastPiece;
	_lastPiece = NULL;
	_lastDstCol = -1;
	_lastDstRow = -1;
	_lastSrcCol = -1;
	_lastSrcRow = -1;
}
Board::~Board() {
	delete [] _brd;
}