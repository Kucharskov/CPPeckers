#pragma once
#include "Utils.h"

/* Forward declaration */
class Board;

class Piece {
protected:
	Color _color;
	Pos _position;
	Board& _board;
	bool _promoted;

	Moves getAttacks();

public:
	Piece(Color, Pos, Board &);

	void move(Pos);
	void promote();
	Moves getLegalMoves();
	Color getColor() const;
	Pos getPosition() const;
	bool isPromoted() const;
};

