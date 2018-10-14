#include "Piece.h"
#include "Board.h"

Piece::Piece(Color c, Pos p, Board &b) :
	_color(c),
	_position(p),
	_board(b),
	_promoted(false) {
}

Moves Piece::getAttacks() {
	Color enemy = (getColor() == Color::WHITE) ? Color::BLACK : Color::WHITE;
	int limit = (_promoted) ? 8 : 2;
	std::array<Pos, 4> variants = {
		std::make_pair(-1, -1),
		std::make_pair(-1, 1),
		std::make_pair(1, -1),
		std::make_pair(1, 1)
	};
	Pos checkPos;
	Moves m;

	for (auto variant : variants) {
		bool flag = false;
		for (int i = 1; i <= limit; i++) {
			checkPos = _position + variant*i;
			if (!_board.isLegitPos(checkPos) || _board.getColor(checkPos) == _color) break;
			if (_board.isEmpty(checkPos)) {
				if (flag) m.push_back(checkPos);
				else continue;
			}
			if (_board.getColor(checkPos) == enemy) {
				if (flag) break;
				else flag = true;
			}
		}
	}

	return m;
}

void Piece::checkPromotion() {
	if ((_color == Color::WHITE && _position.second == 0) || (_color == Color::BLACK && _position.second == 7)) _promoted = true;
}

Moves Piece::getLegalMoves() {
	Moves m = getAttacks();
	Pos checkPos;

	if (m.empty()) {
		if (isPromoted()) {
			std::array<Pos, 4> variants = {
				std::make_pair(-1, -1),
				std::make_pair(-1, 1),
				std::make_pair(1, -1),
				std::make_pair(1, 1)
			};

			for (auto variant : variants) {
				for (int i = 1; i < 8; i++) {
					checkPos = _position + variant*i;
					if (!_board.isLegitPos(checkPos) || !_board.isEmpty(checkPos)) break;
					
					m.push_back(checkPos);
				}
			}
		} else {
			std::array<Pos, 2> variants;
			if (_color == Color::WHITE) {
				variants[0] = { -1, -1 };
				variants[1] = { 1, -1 };
			} else {
				variants[0] = { -1, 1 };
				variants[1] = { 1, 1 };
			}

			for (auto variant : variants) {
				checkPos = _position + variant;
				if (_board.isLegitPos(checkPos) && _board.isEmpty(checkPos)) m.push_back(checkPos);
			}
		}
	}

	return m;
}

void Piece::move(Pos p) {
	_position = p;
	checkPromotion();
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
	Color enemy = (getColor() == Color::WHITE) ? Color::BLACK : Color::WHITE;
	int limit = (_promoted) ? 8 : 2;
	std::array<Pos, 4> variants = {
		std::make_pair(-1, -1),
		std::make_pair(-1, 1),
		std::make_pair(1, -1),
		std::make_pair(1, 1)
	};
	Pos checkPos;

	for (auto variant : variants) {
		bool flag = false;
		for (int i = 1; i <= limit; i++) {
			checkPos = _position + variant*i;
			if (!_board.isLegitPos(checkPos) || _board.getColor(checkPos) == _color) break;
			if (_board.isEmpty(checkPos)) {
				if (flag) return true;
				else continue;
			}
			if (_board.getColor(checkPos) == enemy) {
				if (flag) break;
				else flag = true;
			}
		}
	}

	return false;
}
