#include "NullPiece.h"

NullPiece::NullPiece(int row, int col) : Piece(NULL, '#', row, col, NULL)
{

}

bool NullPiece::isReachable(int row, int col) const
{
	return false;
}