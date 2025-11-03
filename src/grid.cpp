#include "grid.hpp"
#include "game.hpp"
#include "raylib.h"
#include <algorithm>
#include <vector>

#include <format>
#include <iostream>
#include <stdio.h>
#include <string>

// CELL IMPLEMENTATION
Cell::Cell(Color color = PURPLE) : color(color) {
}

// GRID IMPLEMENTATION
Grid::Grid() {
    // cells.resize(rows, std::vector<Cell>(cols));
    // for (int r = 0; r < rows; ++r)
    // for (int c = 0; c < cols; ++c) cells[r][c] = Cell();
};

std::string s = "";

void Grid::draw() {
    // Calculate the no.of rows & cols
    float width = GetScreenWidth(), height = GetScreenHeight();
    int cell_count = 50; // the number of hor./ver. cells
    rows = cell_count, cols = cell_count;

    // Debug
    std::string curr_s = std::format("Window size: {}x{}\n rows:{} cols:{}",
                                     width, height, rows, cols);
    if (s != curr_s) {
        s = curr_s;
        std::cout << curr_s << std::endl;
    }

    // float cell_width = 0.0f, cell_height = 0.0f;
    float cell_width = width / cell_count;
    float cell_height = height / cell_count;

    // DrawRectangle(30, 30, 20, 20, RAYWHITE);

    // void DrawRectangle(int posX, int posY, int width, int height, Color
    // color);
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            DrawRectangleLines(c * cell_height, r * cell_width, cell_width,
                               cell_height, GRAY);
        }
    }
    // DrawRectangle(0, rows - 20, 20, 20, BLACK);
}
