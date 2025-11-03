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
    int start = 16, end = 30;
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
    if (dir == Direction::Down && new_direction == Direction::Up) return;
    if (dir == Direction::Up && new_direction == Direction::Down) return;
    if (dir == Direction::Left && new_direction == Direction::Right) return;
    if (dir == Direction::Right && new_direction == Direction::Left) return;
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

    // Check collision
    if (body_set.count(new_head)) {
        status_msg = "Game Over";
        game_is_running = false;
        return;
    }

    // Check food
    if (new_head.first == food_pos.first &&
        new_head.second == food_pos.second) {
        food_pos = { -1, -1 };
        body.push_back(new_head);
        body_set.insert(new_head);
        head = new_head;
        game_score++;
    } else {
        body.push_back(new_head);
        body.pop_front();
        body_set.erase(body.front()); // remove tail
        body_set.insert(new_head);    // add new head
        head = new_head;
    }

    status_msg = "Head: " + std::to_string(head.first) + ", " +
                 std::to_string(head.second);
}

void Snake::eat(pair<int, int> pos) {
    body.push_front(pos);
}
