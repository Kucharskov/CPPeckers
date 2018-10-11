#include "Piece.h"
#include "Board.h"

Piece::Piece(Color c, Pos p, Board &b) :
	_color(c),
	_position(p),
	_board(b),
	_promoted(false) {
}

Moves Piece::getAttacks() {
	Moves m;
	Pos checkPos;
	Color enemy = (getColor() == Color::WHITE) ? Color::BLACK : Color::WHITE;

	if (isPromoted()) {
		//Not implemented Yet
	} else {
		for (int y = -1; y < 2; y += 2) {
			for (int x = -1; x < 2; x += 2) {
				checkPos = { _position.first + x, _position.second + y };
				if (_board.isLegitPos(checkPos) && _board.getColor(checkPos) == enemy) {
					checkPos = { _position.first + 2 * x, _position.second + 2 * y };
					if (_board.isLegitPos(checkPos) && _board.isEmpty(checkPos))
						m.push_back(checkPos);
				}
			}
		}
	}

	return m;
}

Moves Piece::getLegalMoves() {
	Moves m = getAttacks();
	Pos checkPos;

	if (m.empty()) {
		if (isPromoted()) {
			for (int i = 1; i < 8; i++) {
				checkPos = { _position.first - i, _position.second - i };
				if (!_board.isLegitPos(checkPos)) break;
				if (!_board.isEmpty(checkPos)) break;
				m.push_back(checkPos);
			}
			for (int i = 1; i < 8; i++) {
				checkPos = { _position.first - i, _position.second + i };
				if (!_board.isLegitPos(checkPos)) break;
				if (!_board.isEmpty(checkPos)) break;
				m.push_back(checkPos);
			}
			for (int i = 1; i < 8; i++) {
				checkPos = { _position.first + i, _position.second - i };
				if (!_board.isLegitPos(checkPos)) break;
				if (!_board.isEmpty(checkPos)) break;
				m.push_back(checkPos);
			}
			for (int i = 1; i < 8; i++) {
				checkPos = { _position.first + i, _position.second + i };
				if (!_board.isLegitPos(checkPos)) break;
				if (!_board.isEmpty(checkPos)) break;
				m.push_back(checkPos);
			}
		}
		else {
			int y = (_color == Color::WHITE) ? -1 : 1;
			for (int x = -1; x < 2; x += 2) {
				checkPos = { _position.first + x, _position.second + y };
				if (_board.isLegitPos(checkPos) && _board.isEmpty(checkPos))
					m.push_back(checkPos);
			}
		}
	}

	return m;
}

void Piece::move(Pos p) {
	_position = p;
}

void Piece::promote() {
	_promoted = true;
}

Color Piece::getColor() const {
	return _color;
}

Pos Piece::getPosition() const {
	return _position;
}

bool Piece::isPromoted() const {
	return _promoted;
}

bool Piece::canAttack() const {
	Pos checkPos;
	Color enemy = (getColor() == Color::WHITE) ? Color::BLACK : Color::WHITE;

	if (isPromoted()) {
		//Not implemented Yet
	}
	else {
		for (int y = -1; y < 2; y += 2) {
			for (int x = -1; x < 2; x += 2) {
				checkPos = { _position.first + x, _position.second + y };
				if (_board.isLegitPos(checkPos) && _board.getColor(checkPos) == enemy) {
					checkPos = { _position.first + 2 * x, _position.second + 2 * y };
					if (_board.isLegitPos(checkPos) && _board.isEmpty(checkPos))
						return true;
				}
			}
		}
	}

	return false;
}
