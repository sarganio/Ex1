#pragma once

#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(Player*, int row, int col, Board*);
	virtual bool isLegalMove(int, int) const;
	virtual bool isReachable(int, int)const;

private:

};