#pragma once

#include <SDL2/SDL.h>
#include "../coordinates/coordinates.hpp"
#include "../map/map.hpp"

class Player
{
    public:
        Player(int start_x = 0, int start_y = 0, float start_angle= -90, int _radius = 15);
        ~Player();

        // Update movement
        void update(int move_factor, int rotate_factor, int max_x, int max_y, Map current_map);

        // Render data
        Vec2 pos;
        float radius;
        float angle;
        SDL_Color color;

        // Movement data
        float move_speed, rotate_speed;
};