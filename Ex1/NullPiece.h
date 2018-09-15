#pragma once

#include "Piece.h"

class NullPiece : public Piece
{
public:
	NullPiece(int, int);
	virtual bool isReachable(int, int) const;
private:
};