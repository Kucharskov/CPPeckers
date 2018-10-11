#include "Board.h"
#include "Piece.h"

Board::Board() {
	for (int y = 0; y < 3; y++)
		for (int x = (y + 1) % 2; x < 8; x += 2)
			_pieces.push_back(new Piece(Color::BLACK, {x, y}, *this));
	
	for (int y = 5; y < 8; y++)
		for (int x = (y + 1) % 2; x < 8; x += 2)
			_pieces.push_back(new Piece(Color::WHITE, { x, y }, *this));

	/*
	//Two pieces wchich in next move will be promoted
	_pieces.push_back(new Piece(Color::WHITE, { 4,1 }, *this));
	_pieces.push_back(new Piece(Color::BLACK, { 3,6 }, *this));
	*/
}

void Board::move(Pos from, Pos to) {
	for (auto piece : _pieces) {
		if (piece->getPosition() == from)
			piece->move(to);
	}
}

Piece * Board::getPiece(Pos p) {
	for (auto piece : _pieces) {
		if (piece->getPosition() == p)
			return piece;
	}

	return nullptr;
}

void Board::removePiece(Pos p) {
	_pieces.remove(getPiece(p));
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