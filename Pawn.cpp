#include "Pawn.h"

Pawn::Pawn(Color c, Pos p, Board &b) : Piece(c, p, b) {
}

Moves Pawn::getAttacks() const {
	return {};
}

Moves Pawn::getLegalMoves() const {
	return {};
}

