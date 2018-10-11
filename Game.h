#pragma once
#include <stdexcept>
#include <algorithm> 
#include "Utils.h"
#include "Board.h"

#include <iostream>

class Game {
private:
	Board _board;
	Pos _selected;
	Color _current;

public:
	Game(Color = Color::WHITE);

	void alternateCurrent();
	void selectField(Pos);
	bool move(Pos);
	Color getCurrent() const;
	Result checkWin() const;
	
	//Metody <iostream> - do usuniêcia!
	void draw();
};

