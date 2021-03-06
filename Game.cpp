#include "Game.h"
#include "Piece.h"


Game::Game(Color color) :
	_current(color),
	_selected(-1, -1),
	_lastMove({ -1,-1 }, { -1,-1 }) {

}

void Game::cleanKills(Pos from, Pos to, Color color) {
	Color enemy = (color == Color::WHITE) ? Color::BLACK : Color::WHITE;
	int dx = (to.first - from.first) / abs(to.first - from.first);
	int dy = (to.second - from.second) / abs(to.second - from.second);
	Pos delta = { dx, dy };
	Pos checkPos = from;

	while (checkPos != to) {
		checkPos = checkPos + delta;

		if (_board.getColor(checkPos) == enemy)
			_board.removePiece(checkPos);
	}
}

bool Game::move(Pos pos) {
	if (!_board.isLegitPos(pos)) throw std::invalid_argument("Cant move here, position is incorrect!");
	if (!_board.isEmpty(pos)) throw std::invalid_argument("Cant move here, position is not empty!");
	
	Color color = _board.getColor(_selected);
	if (color != getCurrent()) return false;

	Moves m = _board.getLegalMoves(_selected);
	if (!(std::find(m.begin(), m.end(), pos) != m.end())) return false;

	Moves attackers = _board.getAtackers(color);
	bool killed = false;
	if (!attackers.empty()) {
		if (!(std::find(attackers.begin(), attackers.end(), _selected) != attackers.end())) return false;

		cleanKills(_selected, pos, color);
		killed = true;
	}

	_board.move(_selected, pos);
	alternateCurrent();

	if (killed) {
		attackers = _board.getAtackers(color);
		if ((std::find(attackers.begin(), attackers.end(), pos) != attackers.end()))
			alternateCurrent();
	}

	_lastMove = { _selected, pos };

	return true;
}

void Game::selectPiece(Pos pos) {
	if (!_board.isLegitPos(pos)) throw std::invalid_argument("Cant select, position is incorrect!");
	if (_board.isEmpty(pos)) throw std::invalid_argument("Cant select, position empty!");
	_selected = pos;
}

void Game::alternateCurrent() {
	_current = (_current == Color::WHITE) ? Color::BLACK : Color::WHITE;
}

Color Game::getCurrent() const {
	return _current;
}

Move Game::getLastMove() const {
	return _lastMove;
}

Moves Game::getSelectedMoves() const {
	return _board.getLegalMoves(_selected);
}

Moves Game::getAttackers() const {
	return _board.getAtackers(_current);
}

Result Game::checkWin() const {
	int blackMoves = _board.countColorMoves(Color::BLACK);
	int whiteMoves = _board.countColorMoves(Color::WHITE);

	if (blackMoves == 0 && whiteMoves == 0) return Result::DRAW;
	else if (blackMoves == 0) return Result::WHITE;
	else if (whiteMoves == 0) return Result::BLACK;
	else return Result::NOWIN;
}

void Game::draw() {
	std::cout << "  0 1 2 3 4 5 6 7" << std::endl << std::endl;
	for (int y = 0; y < 8; y++) {
		std::cout << y << " ";
		for (int x = 0; x < 8; x++) {
			if (x > 0) std::cout << "|";
			switch (_board.getColor({ x, y })) {
			case Color::EMPTY:
				std::cout << " ";
				break;
			case Color::WHITE:
				std::cout << (_board.isPromoted({ x, y }) ? "W" : "w");
				break;
			case Color::BLACK:
				std::cout << (_board.isPromoted({ x, y }) ? "B" : "b");
				break;
			}
		}
		std::cout << std::endl;
		if (y < 7) std::cout << "  ---------------" << std::endl;
	}
	std::cout << std::endl;
}