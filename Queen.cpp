#include "Queen.h"

Queen::Queen(Color c, Pos p, Board &b) : Piece(c, p, b) {
}

Moves Queen::getAttacks() const
{
	return {};
}

Moves Queen::getLegalMoves() const
{
	return {};
}
