#include <iostream>
#include "Board.h"

int main() {
	Board b;

	for (int y = 0; y < 8; y++) {
		std::cout << "|";
		for (int x = 0; x < 8; x++) {
			switch (b.getColor({ x, y })) {
			case Color::EMPTY:
				std::cout << " ";
				break;
			case Color::WHITE:
				std::cout << "W";
				break;
			case Color::BLACK:
				std::cout << "B";
				break;
			}
			std::cout << "|";
		}
		std::cout << std::endl;
		if (y < 7) std::cout << "-----------------" << std::endl;
	}

	system("PAUSE");
	return 0;
}