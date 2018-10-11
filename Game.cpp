#include "Game.h"
#include "Piece.h"

Game::Game(Color c) :
	_current(c),
	_selected(-1, -1) {
}

void Game::alternateCurrent() {
	_current = (_current == Color::WHITE) ? Color::BLACK : Color::WHITE;
}

void Game::selectField(Pos p) {
	if (!_board.isLegitPos(p)) throw std::invalid_argument("Cant select, position is incorrect!");
	if (_board.isEmpty(p)) throw std::invalid_argument("Cant select, position empty!");
	_selected = p;
}

bool Game::move(Pos p) {
	if (!_board.isLegitPos(p)) throw std::invalid_argument("Cant move here, position is incorrect!");
	if (!_board.isEmpty(p)) throw std::invalid_argument("Cant move here, position is not empty!");
	
	Piece * piece = _board.getPiece(_selected);
	Color c = piece->getColor();
	if (c != getCurrent()) return false;

	Moves m = piece->getLegalMoves();
	if (std::find(m.begin(), m.end(), p) != m.end()) {
		if (c == Color::WHITE && p.second == 0) {
			piece->promote();
		}
		if (c == Color::BLACK && p.second == 7) {
			piece->promote();
		}
		_board.move(_selected, p);

		int dx = p.first - _selected.first;
		int dy = p.second - _selected.second;
		Color enemy = (c == Color::WHITE) ? Color::BLACK : Color::WHITE;
		bool killer = false;
		
		do {
			if (dx > 0) dx--;
			else if (dx < 0) dx++;
			if (dy > 0) dy--;
			else if (dy < 0) dy++;

			if (_board.getColor({ _selected.first + dx, _selected.second + dy }) == enemy) {
				_board.removePiece({ _selected.first + dx, _selected.second + dy });
				killer = true;
			}
		} while (dx != 0 && dy != 0);

		if(!killer) alternateCurrent();
		return true;
	}

	return false;
}

Color Game::getCurrent() const {
	return _current;
}

Result Game::checkWin() const {
	//Not implemented yet
	return Result::NOWIN;
}

void Game::draw() {
	std::cout << "  0 1 2 3 4 5 6 7" << std::endl << std::endl;
	for (int y = 0; y < 8; y++) {
		std::cout << y << " ";
		for (int x = 0; x < 8; x++) {
			if(x > 0) std::cout << "|";
			switch (_board.getColor({ x, y })) {
			case Color::EMPTY:
				std::cout << " ";
				break;
			case Color::WHITE:
				std::cout << ((_board.getPiece({ x, y })->isPromoted()) ? "W" : "w");
				break;
			case Color::BLACK:
				std::cout << ((_board.getPiece({ x, y })->isPromoted()) ? "B" : "b");
				break;
			}
		}
		std::cout << std::endl;
		if (y < 7) std::cout << "  ---------------" << std::endl;
	}
	std::cout << std::endl;
}
