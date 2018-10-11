#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Queen.h"

Board::Board() {
	for (int y = 0; y < 3; y++)
		for (int x = (y + 1) % 2; x < 8; x += 2)
			_pieces.push_back(new Pawn(Color::BLACK, {x, y}, *this));
	
	for (int y = 5; y < 8; y++)
		for (int x = (y + 1) % 2; x < 8; x += 2)
			_pieces.push_back(new Pawn(Color::WHITE, { x, y }, *this));
}

void Board::move(Pos from, Pos to) {
	for (auto piece : _pieces) {
		if (piece->getPosition() == from)
			piece->move(to);
	}
}

bool Board::isEmpty(Pos p) const {
	return getColor(p) == Color::EMPTY;
}

bool Board::isLegitPos(Pos p) const {
	if (p.first < 0 || p.first >= 8 || p.second < 0 || p.second >= 8) return false;
	return true;
}

Color Board::getColor(Pos p) const {
	for (auto piece : _pieces) {
		if (piece->getPosition() == p)
			return piece->getColor();
	}

	return Color::EMPTY;
}