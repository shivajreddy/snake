#pragma once

#include "globals.hpp"
#include "raylib.h"
#include <deque>

#include <unordered_set>
using std::deque;
using std::pair;
using std::unordered_set;

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
    void change_direction(Direction new_direction);
    void eat(pair<int, int> pos);
    pair<int, int> head;
    deque<pair<int, int>> body;
    unordered_set<pair<int, int>> body_set;
};
