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

	void cleanKills(Pos, Pos, Color);

public:
	Game(Color = Color::WHITE);

	bool move(Pos);
	void selectPiece(Pos);
	void alternateCurrent();
	Color getCurrent() const;
	Result checkWin() const;
	
	//Metody <iostream> - do usuniêcia!
	void draw();
	void getSelectedMoves();
	void getAttacers();
};

