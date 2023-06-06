#include "collision.hpp"

bool PlayerCollides(Vec2* player_pos, int player_radius, Map map)
{
    for (int i = 0; i < map.cells.size(); i++)
    {
        SDL_Rect cell = map.cells[i];
        if (map.info[i] != '#') continue;

        int dx;
        if (player_pos->x < cell.x)
            dx = cell.x - player_pos->x;
        else if (player_pos->x > cell.x + cell.w)
            dx = player_pos->x - (cell.x + cell.w);
        else
        {
            dx = 0;
        }
        
        int dy;
        if (player_pos->y < cell.y)
            dy = cell.y - player_pos->y;
        else if (player_pos->y > cell.y + cell.h)
            dy = player_pos->y - (cell.y + cell.h);
        else
        {
            dy = 0;
        }

        if (abs(dx) < player_radius && abs(dy) < player_radius)
        {
            return true;
        }
    }

    return false;
}