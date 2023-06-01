#pragma once

#include "vector2.hpp"
#include <vector>
#include "direction.hpp"

class Snake
{
    public:
        Snake(int start_x = 5, int start_y = 5, int start_size = 3, Direction start_direction = Direction::East);
        ~Snake();
        void move();
        void ChangeDirection(Direction direction);
        int size;
        std::vector<Vector2> body;
    private:
        int head_x, head_y;
        Vector2 direction_vector;
        Direction direction;
};