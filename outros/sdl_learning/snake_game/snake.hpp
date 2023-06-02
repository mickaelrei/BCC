#pragma once

#include "vector2.hpp"
#include <vector>
#include "direction.hpp"

class Snake
{
    public:
        Snake(int start_x = 7, int start_y = 3, int start_size = 3, Direction start_direction = Direction::East);
        ~Snake();
        void update(bool borders = false, int cols = 0, int rows = 0);
        void ChangeDirection(Direction direction);
        void grow(int amount = 1);
        bool CheckDead(bool borders, int cols, int rows);
        std::vector<Vec2> body;
    private:
        int head_x, head_y, grow_queue;
        Vec2 direction_vector;
        Direction direction;
};