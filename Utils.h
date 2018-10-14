#pragma once
#include <utility>
#include <list>

//Enum opisuj�cy kolory figur
enum class Color { EMPTY, BLACK, WHITE };

//Enum opisuj�cy mo�liwe wyniki gry
enum class Result { NOWIN, BLACK, WHITE, DRAW };

//Pozycja jako para
using Pos = std::pair<int, int>;

//Lista ruch�w jako lista pozycji
using Moves = std::list<Pos>;

//Operatory dla pozycji
inline
Pos operator+(const Pos &a, const Pos &b) {
	return{ a.first + b.first, a.second + b.second };
}

inline
Pos operator*(const Pos &a, const int &b) {
	return{ a.first * b, a.second * b };
}