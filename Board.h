#pragma once
#include <list>
#include "Utils.h"

/* Forward declaration */
class Piece;

class Board {
private:
	std::list<Piece *> _pieces;

public:
	Board();

	void move(Pos, Pos);
	Piece * getPiece(Pos);
	void removePiece(Pos);
	bool isEmpty(Pos) const;
	bool isLegitPos(Pos) const;
	Color getColor(Pos) const;
};

