#pragma once

#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include "../coordinates/coordinates.hpp"

struct Map
{
    std::vector<SDL_Rect> cells;
    std::string info;
    Vec2i size;
    SDL_Color wall_color, floor_color;
};