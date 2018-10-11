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

		g.getAttacers();

		int choose;
		std::cout << "Pick piece: ";
		std::cin >> choose;
		g.selectPiece({ choose / 10, choose % 10 });

		g.getSelectedMoves();

		std::cout << "Move piece to: ";
		std::cin >> choose;
		err = !g.move({ choose / 10, choose % 10 });
		system("PAUSE");
	} while (g.checkWin() == Result::NOWIN);

	system("PAUSE");
	return 0;
}