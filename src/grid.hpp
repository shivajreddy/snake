#pragma once

#include "raylib.h"
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
    int cell_size;
    std::vector<std::vector<Cell>> cells;

public:
    Grid();
    void draw();
};
