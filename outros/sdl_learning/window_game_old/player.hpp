#pragma once

#include "vec2.hpp"

class Player
{
    public:
        Player(int start_x = 0, int start_y = 0, float start_angle= -90, int _radius = 15);
        ~Player();
        void update(int move_factor, int rotate_factor, int max_x, int max_y);
        Vec2 pos;
        float radius;
        float angle;
        float move_speed, rotate_speed;
};