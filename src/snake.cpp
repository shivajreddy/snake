#include "snake.hpp"
#include "raylib.h"

using std::pair;

Snake::Snake() {
    dir = Direction::Right;
    head = { 30, 30 };
    // Initialize body from tail to head: [tail ... head]
    for (int i = 0; i < 3; ++i) {
        body.push_back({ 30, 28 + i });
    }
}

void Snake::draw() {
    // Demo draw snake
    float width = GetScreenWidth(), height = GetScreenHeight();
    int cell_count = 50; // the number of hor./ver. cells
    float cell_width = width / cell_count;
    float cell_height = height / cell_count;

    for (auto [r, c] : body) {
        DrawRectangle(c * cell_height, r * cell_width, cell_width, cell_height,
                      RED);
    }
}

void Snake::move() {
    switch (dir) {
    case Direction::Left: {
        break;
    }
    case Direction::Right: {
        pair<int, int> new_head = { head.first, head.second + 1 };
        body.push_back(new_head);
        body.pop_front();
        head = new_head;
        break;
    }
    }
}

void Snake::eat(pair<int, int> pos) {
    body.push_front(pos);
}
