#include "Game.h"
#include "Piece.h"

Game::Game(Color color) :
	_current(color),
	_selected(-1, -1) {
}

void Game::cleanKills(Pos from, Pos to, Color color) {
	int dx = from.first - to.first;
	int dy = from.second - to.second;
	Color enemy = (color == Color::WHITE) ? Color::BLACK : Color::WHITE;

	do {
		if (dx > 0) dx--;
		else if (dx < 0) dx++;
		if (dy > 0) dy--;
		else if (dy < 0) dy++;

		if (_board.getColor({ to.first + dx, to.second + dy }) == enemy) {
			_board.removePiece({ to.first + dx, to.second + dy });
		}
	} while (dx != 0 && dy != 0);
}

bool Game::checkPromotion(Pos pos, Color color) {
	return (color == Color::WHITE && pos.second == 0) || (color == Color::BLACK && pos.second == 7);
}

void Game::alternateCurrent() {
	_current = (_current == Color::WHITE) ? Color::BLACK : Color::WHITE;
}

void Game::selectPiece(Pos pos) {
	if (!_board.isLegitPos(pos)) throw std::invalid_argument("Cant select, position is incorrect!");
	if (_board.isEmpty(pos)) throw std::invalid_argument("Cant select, position empty!");
	_selected = pos;
}

bool Game::move(Pos pos) {
	if (!_board.isLegitPos(pos)) throw std::invalid_argument("Cant move here, position is incorrect!");
	if (!_board.isEmpty(pos)) throw std::invalid_argument("Cant move here, position is not empty!");
	
	Piece * piece = _board.getPiece(_selected);
	Color color = piece->getColor();
	if (color != getCurrent()) return false;

	Moves m = piece->getLegalMoves();
	if (!(std::find(m.begin(), m.end(), pos) != m.end())) return false;

	Moves attackers = _board.getAtackers(color);
	if (!attackers.empty()) {
		if (!(std::find(attackers.begin(), attackers.end(), _selected) != attackers.end())) return false;

		cleanKills(pos, _selected, color);
		alternateCurrent();
	}

	if (checkPromotion(pos, color)) {
		piece->promote();
	}

	_board.move(_selected, pos);
	alternateCurrent();
	return true;
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

void Game::getSelectedMoves() {
	Moves m = _board.getPiece(_selected)->getLegalMoves();

	std::cout << "Moves: ";
	for (auto e : m) std::cout << e.first << e.second << ", ";
	std::cout << std::endl;
}

void Game::getAttacers() {
	Moves m = _board.getAtackers(_current);

	std::cout << "Atackers: ";
	for (auto e : m) std::cout << e.first << e.second << ", ";
	std::cout << std::endl;
}
