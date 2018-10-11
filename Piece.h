#pragma once
#include "Utils.h"

/* Forward declaration */
class Board;

class Piece {
protected:
	Color _color;
	Pos _position;
	Board& _board;

	virtual Moves getAttacks() const = 0;

public:
	Piece(Color, Pos, Board &);

	void move(Pos);
	Color getColor() const;
	Pos getPosition() const;
	virtual Moves getLegalMoves() const = 0;
};

