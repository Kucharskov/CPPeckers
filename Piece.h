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

	Moves getAttacks();
	void checkPromotion();

public:
	Piece(Color, Pos, Board &);

	void move(Pos);
	Moves getLegalMoves();
	Color getColor() const;
	Pos getPosition() const;
	bool isPromoted() const;
	bool canAttack() const;
};

