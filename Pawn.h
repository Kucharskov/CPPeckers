#pragma once
#include "Piece.h"

class Pawn : public Piece {
protected:
	Moves getAttacks() const;

public:
	Pawn(Color, Pos, Board &);

	Moves getLegalMoves() const;
};

