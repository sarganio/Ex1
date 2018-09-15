#pragma once

#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(Player*, int row, int col, Board*);
	virtual bool isReachable(int, int) const;

private:

};