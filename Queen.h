#pragma once
#include "Piece.h"

class Queen : public Piece {
protected:
	Moves getAttacks() const;

public:
	Queen(Color, Pos, Board &);

	Moves getLegalMoves() const;
};

