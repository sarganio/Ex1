#pragma once

#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(Player*, int row, int col, Board*);
	virtual bool isReachable(int, int) const;

private:

};