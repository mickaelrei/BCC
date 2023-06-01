#include <vector>
#include <iostream>
#include "snake.hpp"
#include "vector2.hpp"
#include "direction.hpp"

Vector2 DirectionToVector2(Direction direction)
{
    switch (direction)
    {
        case Direction::North:
            return Vector2(0, -1);
        case Direction::South:
            return Vector2(0, 1);
        case Direction::East:
            return Vector2(1, 0);
        case Direction::West:
            return Vector2(-1, 0);
    }

    // By default, return zero vector
    return Vector2(0, 0);
}

Snake::Snake(int start_x, int start_y, int start_size, Direction start_direction)
{
    // Convert direction
    direction = start_direction;
    direction_vector = DirectionToVector2(start_direction);

    // Start position
    Vector2 start_pos = Vector2(start_x, start_y);

    // Alloc body
    size = start_size;
    body = std::vector<Vector2>();

    // Create body
    std::cout << "Startint to create\n";
    for (int i = 0; i < start_size; i++) {
        Vector2 bodypart_pos = start_pos - direction * i;
        std::cout << "body[" << i << "] = (" << bodypart_pos.x << ", " << bodypart_pos.y << ")\n";
        body.push_back(bodypart_pos);
    }
    std::cout << "Finished creating\n";
}

Snake::~Snake()
{
    // delete *body;
}

void Snake::move()
{
    // Move all body parts
    std::cout << "Updating body\n";
    for (int i = 0; i < size; i++)
    {
        body[i] = body[i] + direction_vector;
        std::cout << "body[" << i << "] = (" << body[i].x << ", " << body[i].y << ")\n";
    }
}

void Snake::ChangeDirection(Direction new_direction)
{
    if (direction == new_direction)
        return;

    // Check if new_direction is valid
    if (
        direction == Direction::North && new_direction == Direction::South ||       // Heading north, can't go south
        direction == Direction::South && new_direction == Direction::North ||       // Heading south, can't go north
        direction == Direction::East  && new_direction == Direction::West  ||       // Heading east, can't go west
        direction == Direction::West  && new_direction == Direction::East           // Heading west, can't go east
    )
    {
        return;
    }

    // Here, new_direction is always valid
    direction_vector = DirectionToVector2(new_direction);
}