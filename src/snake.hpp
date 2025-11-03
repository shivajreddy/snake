#pragma once

#include "game.hpp"
#include "raylib.h"
#include <deque>

using std::deque;
using std::pair;

/*
. . . . . . . . . . .
. . . . . . . . . . .
. . - - - - . . . . .
. . . . . . . . . . .
. . . . . . . . . . .
. . . . . . . . . . .
*/

enum class Direction {
    Left,
    Right,
    Up,
    Down,
};

class Snake {
public:
    Direction dir;

public:
    Snake();
    void draw();
    void move();
    void eat(pair<int, int> pos);
    pair<int, int> head;
    deque<pair<int, int>> body;
};
