#pragma once

#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Player*, int row, int col, Board*);
	virtual bool isReachable(int, int) const;
private:
};