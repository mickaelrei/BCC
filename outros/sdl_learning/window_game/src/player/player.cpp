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

Player::Player(Map* map, float start_x, float start_y, float start_angle, int _radius)
{
    pos = Vec2f{start_x, start_y};
    angle = start_angle;
    radius = _radius;

    _map = map;

    move_speed = 5;
    rotate_speed = 3;

    color = {50, 50, 50, 255};
}

Player::~Player()
{
    
}

void Player::update(int move_factor, int rotate_factor, int max_x, int max_y)
{
    angle += rotate_factor * rotate_speed;

    float add_x = cosf(angle / 180 * M_PI) * move_factor * move_speed;
    float add_y = sinf(angle / 180 * M_PI) * move_factor * move_speed;

    // Check for collision when moving only on X axis
    Vec2f new_pos_x = {pos.x + add_x, pos.y};
    if (!PlayerCollides(&new_pos_x, radius, _map))
        pos.x = clamp(new_pos_x.x, 0, max_x);

    // Check on Y
    Vec2f new_pos_y = {pos.x, pos.y + add_y};
    if (!PlayerCollides(&new_pos_y, radius, _map))
        pos.y = clamp(new_pos_y.y, 0, max_y);

    // Try to move, checking for collisions
    // pos.x = clamp(pos.x + add_x, 0, max_x);
    // pos.y = clamp(pos.y + add_y, 0, max_y);
}