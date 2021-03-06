#include "Piece.h"
#include <string>
#include <iostream>
#include "King.h"
#include "Knight.h"

using namespace std;

class King;
class Knight;


Piece::Piece(Player* pl, char sign, int row, int col, Board* board) :
			_player(pl), _row(row), _col(col), _brd(board), _startRow(row), _startCol(col)
{
	if (pl != NULL && pl->isWhite())
	{
		_sign = toupper(sign);
	}
	else
	{
		_sign = tolower(sign);
	}
}

Piece::~Piece()
{

}

char Piece::getSign() const
{
	return _sign;
}

Player* Piece::getPlayer() const
{
	return _player;
}

void Piece::setPosition(int row, int col) 
{
	_row = row;
	_col = col;
}
bool Piece::isWayFree(int dstRow, int dstCol) const
{
	Piece*** matBoard = _brd->getBoard();
	Piece* currPiece = NULL;
	int  i,j;
	// move on the col only
	if (_row == dstRow)
	{
		int startCol = _col < dstCol ? _col : dstCol;
		int endCol = _col < dstCol ? dstCol : _col;

		for (j = startCol + 1; j < endCol ; ++j)
		{
			//*(matBoard  + _row * BOARD_SIZE + j)
			currPiece = matBoard[_row][j];

			// if there is player that own the piece
			if (currPiece->getPlayer() != NULL)
			{
				return false;
			}
		}

		return true;
	}
	
	// move on the rows only
	if (_col == dstCol) 
	{
		int startRow = _row < dstRow ? _row : dstRow;
		int endRow = _row < dstRow ? dstRow : _row;

		for (i = startRow + 1; i < endRow; ++i)
		{
			//*(matBoard + i * BOARD_SIZE + _col);
			currPiece = matBoard[i][_col];

			// if there is player that own the piece
			if (currPiece->getPlayer() != NULL)
			{
				return false;
			}
		}

		return true;
	}


	// check diagonal move
	int startRow = dstRow < _row ? dstRow : _row;
	int endRow = dstRow < _row ? _row : dstRow;
	int startCol;

	int num = 1;
	if (_row < dstRow)

	{
		startCol = _col;
		if (_col > dstCol)
		{
			num = -1;
		}
	}
	else 
	{
		startCol = dstCol;
		if (_col < dstCol)
		{
			num = -1;
		}
	}

	for (i = startRow + 1, j = startCol+num; i < endRow ; ++i)
	{
		//*(matBoard + i * 8 + j);
		currPiece = matBoard[i][j];

		// check if the board in the place contains null piece
		if (currPiece->getPlayer() != NULL)
		{
			return false;
		}
		j += num;
	}

	return true;
}
bool Piece::isLegalMove(int row, int col) {
	//reachable + free way + non friendly piece at destination =>true , otherwise =>false
	bool IsChess, IsReachable, IsWayFree, IsDestinationClear;
	int originalRow = _row, originalCol = _col;//for restoration of original row and col
	
	IsReachable = isReachable(row, col);
	//Knight can jump over any pieces
	if (typeid(*this) == typeid(Knight))
		IsWayFree = true;
	else
		IsWayFree = isWayFree(row, col);

	IsDestinationClear = isDestinationClear(row, col);

	if (!IsReachable || !IsWayFree || !IsDestinationClear)
		return false;
	_row = row;
	_col = col;
	IsChess = _player->getKing()->isChess();
	_row = originalRow;
	_col = originalCol;
return IsChess;
}
bool Piece::isDestinationClear(int row, int col)const {
	Piece*** brd = _brd->getBoard();
	return brd[row][col]->getPlayer()->isWhite() != this->getPlayer()->isWhite();
}

