#pragma once

#include "raylib.h"
#include "snake.hpp"
#include <vector>

class Cell {
public:
    Color color;

public:
    Cell(Color color);
};

class Grid {
public:
    int rows;
    int cols;
    float cell_width;
    float cell_height;
    std::vector<std::vector<Cell>> cells;
    Snake& snake;

public:
    Grid(Snake& snake);
    void draw();
    void generate_food();
};
