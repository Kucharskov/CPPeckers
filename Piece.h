#pragma once
#include <array>
#include "Utils.h"

/* Forward declaration */
class Board;

class Piece {
protected:
	Color _color;
	Pos _position;
	Board& _board;
	bool _promoted;

	void checkPromotion();
	Moves getAttacks() const;

public:
	Piece(Color, Pos, Board &);

	void move(Pos);
	bool canAttack() const;
	bool isPromoted() const;
	Color getColor() const;
	Pos getPosition() const;
	Moves getLegalMoves() const;
};

