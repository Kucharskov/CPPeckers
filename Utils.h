#pragma once
#include <utility>
#include <list>

//Enum opisuj¹cy kolory figur
enum class Color { EMPTY, BLACK, WHITE };

//Pozycja jako para
using Pos = std::pair<int, int>;

//Lista ruchów jako lista pozycji
using Moves = std::list<Pos>;