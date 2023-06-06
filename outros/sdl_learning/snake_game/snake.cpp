#include <vector>
#include <iostream>
#include "snake.hpp"
#include "vector2.hpp"
#include "direction.hpp"

Vec2 DirectionToVector2(Direction direction)
{
    switch (direction)
    {
        case Direction::North:
            return Vec2{0, -1};
        case Direction::South:
            return Vec2{0, 1};
        case Direction::West:
            return Vec2{-1, 0};
        case Direction::East:
            return Vec2{1, 0};
    }

    // By default, return zero vector
    return Vec2{0, 0};
}

Snake::Snake(int start_x, int start_y, int _start_size, Direction start_direction)
{
    // Convert direction
    direction = start_direction;
    direction_vector = DirectionToVector2(start_direction);

    // Alloc body
    start_size = _start_size;
    body = std::vector<Vec2>();

    // Create body
    for (int i = 0; i < start_size; i++) {
        int x = start_x - direction_vector.x * i;
        int y = start_y - direction_vector.y * i;
        body.push_back(Vec2{x, y});
    }

    // Initialize grow queue as zero
    grow_queue = 0;
}

bool Snake::CheckDead(bool borders, int cols, int rows)
{
    // Check for borders collision
    if (borders)
    {
        // Hits wall
        if (body[0].x < 0 || body[0].x >= cols || body[0].y < 0 || body[0].y >= rows)
        {
            return true;
        }

    }

    // Check for self collision with head
    for (int i = 1; i < body.size(); i++)
    {
        if (body[0].x == body[i].x && body[0].y == body[i].y)
        {
            return true;
        }
    }

    // No border or self collision, not dead
    return false;
}

Snake::~Snake()
{
    // delete *body;
}

void Snake::grow(int amount)
{
    grow_queue += amount;
}

void Snake::update(bool borders, int cols, int rows)
{
    // Get head new position
    int head_x = body[0].x + direction_vector.x;
    int head_y = body[0].y + direction_vector.y;
    if (!borders)
    {
        // Modulus doesn't work correctly with negative numbers
        while (head_x < 0)
            head_x += cols;
        while (head_y < 0)
            head_y += rows;

        head_x %= cols;
        head_y %= rows;
    }

    // If grow queue is bigger than zero, don't shift body and instead insert new head
    if (grow_queue > 0)
    {
        body.insert(body.begin(), Vec2{head_x, head_y});
        grow_queue--;
        return;
    }

    // Shift all body parts towards head
    for (int i = body.size() - 1; i > 0; i--)
    {
        body[i].x = body[i - 1].x;
        body[i].y = body[i - 1].y;
    }

    // Move head
    body[0].x = head_x;
    body[0].y = head_y;
}

std::string DirectionToString(Direction d)
{
    switch (d) {
        case Direction::North:
            return "North";
        case Direction::South:
            return "South";
        case Direction::East:
            return "East";
        case Direction::West:
            return "West";
    }

    return "";
}

void Snake::ChangeDirection(Direction new_direction)
{
    if (direction == new_direction)
        return;

    // Check if new_direction is valid
    if (
        (direction == Direction::North && new_direction == Direction::South) ||       // Heading north, can't go south
        (direction == Direction::South && new_direction == Direction::North) ||       // Heading south, can't go north
        (direction == Direction::East  && new_direction == Direction::West)  ||       // Heading east, can't go west
        (direction == Direction::West  && new_direction == Direction::East)           // Heading west, can't go east
    )
    {
        return;
    }

    // Here, new_direction is always valid
    direction = new_direction;
    direction_vector = DirectionToVector2(new_direction);
}