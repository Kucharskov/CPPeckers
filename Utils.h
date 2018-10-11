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