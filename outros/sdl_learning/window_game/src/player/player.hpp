#pragma once

#include <SDL2/SDL.h>
#include "../coordinates/coordinates.hpp"
#include "../map/map.hpp"

class Player
{
    public:
        Player() {};
        Player(Map* map, float start_x = 0, float start_y = 0, float start_angle = -90, int _radius = 15);
        ~Player();

        // Update movement
        void update(int move_factor, int rotate_factor, int max_x, int max_y);

        // Render data
        Vec2f pos;
        float radius;
        float angle;
        SDL_Color color;

    private:
        // Current map
        Map* _map;

        // Movement data
        float move_speed, rotate_speed;
};