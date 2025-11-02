#include "raylib.h"
#include <stdio.h>

// GAME CONSTANTS
const char* GAME_NAME = "Snake";
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int GAME_FPS = 60;

class Cell {
    Color color;
};

class Grid {};

class Game {};

void create_grid(int width, int height);

// Snake Game entry point
int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    SetTargetFPS(GAME_FPS);

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(PURPLE);

        create_grid(SCREEN_WIDTH, SCREEN_HEIGHT);

        EndDrawing();
    }

    return 0;
}
