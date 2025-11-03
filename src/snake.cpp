#include "snake.hpp"
#include "globals.hpp"
#include "raylib.h"

#include <string>
#include <unordered_set>
using std::pair;
using std::unordered_set;

Snake::Snake() {
    dir = Direction::Right;
    head = { 30, 30 };
    // Initialize body from tail to head: [tail ... head]
    int start = 24, end = 30;
    for (; start <= end; ++start) {
        body.push_back({ 30, start });
        body_set.insert({ 30, start });
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

void Snake::change_direction(Direction new_direction) {
    if (new_direction == dir) return;
    dir = new_direction;
    move();
}

void Snake::move() {
    pair<int, int> new_head;
    switch (dir) {
    case Direction::Left:
        new_head = { head.first, head.second - 1 };
        break;
    case Direction::Right:
        new_head = { head.first, head.second + 1 };
        break;
    case Direction::Up:
        new_head = { head.first - 1, head.second };
        break;
    case Direction::Down:
        new_head = { head.first + 1, head.second };
        break;
    }

    if (body_set.count(new_head)) {
        status_msg = "Game Over";
        return;
    }

    body.push_back(new_head);
    body.pop_front();
    head = new_head;

    status_msg = "Head: " + std::to_string(head.first) + ", " +
                 std::to_string(head.second);
}

void Snake::eat(pair<int, int> pos) {
    body.push_front(pos);
}
