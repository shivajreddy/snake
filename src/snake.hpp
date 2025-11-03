#pragma once

#include "globals.hpp"
#include "raylib.h"
#include <deque>
#include <unordered_set>
#include <utility>
using std::deque;
using std::pair;
using std::unordered_set;

// Forward Declaration - we are telling compiler that Grid exists
class Grid;

enum class Direction {
    Left,
    Right,
    Up,
    Down,
};

struct PairHash {
    std::size_t operator()(const std::pair<int, int>& p) const noexcept {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

class Snake {

public:
    Direction dir;
    Grid* grid;

public:
    Snake();
    void draw();
    void move();
    void change_direction(Direction new_direction);
    void eat(pair<int, int> pos);
    pair<int, int> head;
    deque<pair<int, int>> body;
    unordered_set<pair<int, int>, PairHash> body_set;
};
