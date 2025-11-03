#include "grid.hpp"
#include "globals.hpp"
#include "raylib.h"
#include "snake.hpp"
#include <algorithm>
#include <vector>

#include <format>
#include <iostream>
#include <random>
#include <stdio.h>
#include <string>

// CELL IMPLEMENTATION
Cell::Cell(Color color = PURPLE) : color(color) {
}

std::string s = "";
// GRID IMPLEMENTATION
Grid::Grid(Snake& _snake) : snake(_snake) {
    // Calculate the no.of rows & cols
    float width = GetScreenWidth(), height = GetScreenHeight();
    int cell_count = 50; // the number of hor./ver. cells

    rows = cell_count;
    cols = cell_count;
    cell_width = width / cell_count;
    cell_height = height / cell_count;

    // Debug
    std::string curr_s = std::format("Window size: {}x{}\n rows:{} cols:{}",
                                     width, height, rows, cols);
    if (s != curr_s) {
        s = curr_s;
        std::cout << curr_s << std::endl;
    }
};

void Grid::generate_food() {
    // Pick any where on the grid, that is not snake
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> row_dist(3, rows - 1);
    std::uniform_int_distribution<> col_dist(3, cols - 1);
    int random_r, random_c;
    do {
        random_r = row_dist(gen);
        random_c = col_dist(gen);
    } while (snake.body_set.count({ random_r, random_c }));
    food_pos = { random_r, random_c };
    // printf("Food pos %d,%d  %d:%d\n", rows, cols, random_r, random_c);
}

void Grid::draw() {
    // Draw the grid
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            DrawRectangleLines(c * cell_height, r * cell_width, cell_width,
                               cell_height, GRAY);
        }
    }
    if (food_pos.first == -1 || food_pos.second == -1) generate_food();
    // Draw the food
    DrawRectangle(food_pos.second * cell_height, food_pos.first * cell_width,
                  cell_width, cell_height, PINK);
}
