#pragma once
#include <list>
#include "Utils.h"

/* Forward declaration */
class Piece;
class Pawn;
class Queen;

class Board {
private:
	std::list<Piece *> _pieces;

public:
	Board();

	void move(Pos, Pos);
	bool isEmpty(Pos) const;
	bool isLegitPos(Pos) const;
	Color getColor(Pos) const;

	//friend class Piece;
};

