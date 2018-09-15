

#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(Player*, int row, int col, Board*);
	virtual bool isReachable(int, int) const;

private:

};