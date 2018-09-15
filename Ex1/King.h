#pragma once
#include "Piece.h"

class Piece;
class Player;
class Board;

class King : public Piece
{
public:
	King(Player*, int row, int col, Board*);
	virtual bool isReachable(int, int)const;
	bool isChess();

private:

};