#include "Piece.h"
#include "Board.h"

Piece::Piece(Color c, Pos p, Board &b) :
	_color(c),
	_position(p),
	_board(b) {
}

void Piece::move(Pos p) {
	_position = p;
}

Color Piece::getColor() const {
	return _color;
}

Pos Piece::getPosition() const {
	return _position;
}
