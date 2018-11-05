#include <iostream>
#include "Game.h"

int main() {
	Game g;
	
	bool err = false;
	do {
		system("CLS");
		g.draw();
		std::cout << "Turn: " << ((g.getCurrent() == Color::WHITE) ? "White" : "Black") << std::endl;

		if (err) std::cout << "Wrong move!" << std::endl;

		std::cout << "Atackers: ";
		for (auto e : g.getAttackers()) std::cout << e.first << e.second << ", ";
		std::cout << std::endl;

		int choose;
		std::cout << "Pick piece: ";
		std::cin >> choose;
		g.selectPiece({ choose / 10, choose % 10 });

		std::cout << "Moves: ";
		for (auto e : g.getSelectedMoves()) std::cout << e.first << e.second << ", ";
		std::cout << std::endl;

		std::cout << "Move piece to: ";
		std::cin >> choose;
		err = !g.move({ choose / 10, choose % 10 });
		system("PAUSE");
	} while (g.checkWin() == Result::NOWIN);

	switch (g.checkWin()) {
		case Result::BLACK:
			std::cout << "BLACK WIN!" << std::endl;
			break;
		case Result::WHITE:
			std::cout << "WHITE WIN!" << std::endl;
			break;
		case Result::DRAW:
			std::cout << "DRAW!" << std::endl;
			break;
	}

	system("PAUSE");
	return 0;
}