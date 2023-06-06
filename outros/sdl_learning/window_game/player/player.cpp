#include <iostream>
#include <math.h>
#include "player.hpp"
#include "../map/map.hpp"
#include "../collision/collision.hpp"

int clamp(int x, int min, int max)
{
    if (x < min)
        return min;
    else if (x > max)
        return max;
    else
        return x;
}

Player::Player(int start_x, int start_y, float start_angle, int _radius)
{
    pos = Vec2{start_x, start_y};
    angle = start_angle;
    radius = _radius;

    move_speed = 5;
    rotate_speed = 3;

    color = {50, 50, 50, 255};
}

Player::~Player()
{
    
}

void Player::update(int move_factor, int rotate_factor, int max_x, int max_y, Map current_map)
{
    angle += rotate_factor * rotate_speed;

    float add_x = cosf(angle / 180 * M_PI) * move_factor * move_speed;
    float add_y = sinf(angle / 180 * M_PI) * move_factor * move_speed;

    // Try to move, checking for collisions
    pos.x = clamp(pos.x + add_x, 0, max_x);
    pos.y = clamp(pos.y + add_y, 0, max_y);
}