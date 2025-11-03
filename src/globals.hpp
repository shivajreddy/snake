#pragma once

#include <string>

// GAME CONSTANTS
inline const char* GAME_NAME = "Snake";
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int GAME_FPS = 60;

extern bool game_is_running;

extern std::string status_msg;
extern int game_score;
