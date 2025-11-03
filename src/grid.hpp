#pragma once

#include "raylib.h"
// #include "snake.hpp"
#include <vector>

class Cell {
public:
    Color color;

public:
    Cell(Color color);
};

class Snake;

class Grid {

public:
    Snake* snake;
    int rows;
    int cols;
    float cell_width;
    float cell_height;
    std::vector<std::vector<Cell>> cells;

public:
    Grid();
    void draw();
    void generate_food();
};
