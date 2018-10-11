#pragma once
#include <utility>
#include <list>

//Enum opisuj�cy kolory figur
enum class Color { EMPTY, BLACK, WHITE };

//Pozycja jako para
using Pos = std::pair<int, int>;

//Lista ruch�w jako lista pozycji
using Moves = std::list<Pos>;