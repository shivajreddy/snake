#include "globals.hpp"
#include "grid.hpp"
#include "raylib.h"
#include "snake.hpp"
#include <string>

#include <stdio.h>

// Snake Game entry point
int main() {
    // SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    // SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI |
    // FLAG_WINDOW_UNDECORATED);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    SetWindowMinSize(400, 300);
    SetTargetFPS(GAME_FPS);

    Grid grid = Grid();
    Snake snake = Snake();

    double prev_time = 0;

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        // Every
        double duration = 0.4d;
        float curr_time = GetTime();
        if (curr_time - prev_time >= duration) {
            prev_time = curr_time;
            snake.move();
        }

        grid.draw();
        snake.draw();
        DrawText(status_msg.c_str(), 20, 20, 30, DARKBLUE);

        // --- INPUT LOGIC ---
        if (IsKeyPressed(KEY_RIGHT)) snake.change_direction(Direction::Right);
        if (IsKeyPressed(KEY_LEFT)) snake.change_direction(Direction::Left);
        if (IsKeyPressed(KEY_UP)) snake.change_direction(Direction::Up);
        if (IsKeyPressed(KEY_DOWN)) snake.change_direction(Direction::Down);

        EndDrawing();
    }

    return 0;
}
