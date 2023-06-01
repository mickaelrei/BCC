#pragma once

class Vector2
{
    public:
        int x;
        int y;
        Vector2(int _x = 0, int _y = 0);
        ~Vector2() {};

        Vector2 operator+(Vector2 other)
        {
            return Vector2(x + other.x, y + other.y);
        };

        Vector2 operator-(Vector2 other)
        {
            return Vector2(x - other.x, y - other.y);
        }

        Vector2 *operator+=(Vector2 other)
        {
            this->x += other.x;
            this->y += other.y;
            return this;
        }

        Vector2 *operator-=(Vector2 other)
        {
            this->x -= other.x;
            this->y -= other.y;
            return this;
        }

        Vector2 operator*(int factor)
        {
            return Vector2(x * factor, y * factor);
        }
};