#include "globals.hpp"
#include "grid.hpp"
#include "raylib.h"
#include "snake.hpp"
#include <string>

#include <stdio.h>

// Snake Game entry point
int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    SetWindowMinSize(400, 300);
    SetTargetFPS(GAME_FPS);

    Snake snake = Snake();
    Grid grid = Grid(snake);

    double prev_time = 0;

    game_is_running = true;
    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        grid.draw();
        // grid.generate_food(snake);

        // Every
        double duration = 0.25d;
        float curr_time = GetTime();
        if (curr_time - prev_time >= duration) {
            prev_time = curr_time;
            snake.move();
        }

        if (game_is_running) snake.draw();

        std::string gs = "Score: " + std::to_string(game_score);
        DrawText(gs.c_str(), 20, 10, 30, DARKBLUE);
        DrawText(status_msg.c_str(), 20, 40, 30, DARKBLUE);

        // --- INPUT LOGIC ---
        if (IsKeyPressed(KEY_RIGHT)) snake.change_direction(Direction::Right);
        if (IsKeyPressed(KEY_LEFT)) snake.change_direction(Direction::Left);
        if (IsKeyPressed(KEY_UP)) snake.change_direction(Direction::Up);
        if (IsKeyPressed(KEY_DOWN)) snake.change_direction(Direction::Down);

        EndDrawing();
    }

    return 0;
}
