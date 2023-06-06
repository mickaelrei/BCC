#include "collision.hpp"

bool PlayerCollides(Player* player, std::vector<MapCell> map_cells)
{
    for (int i = 0; i < map_cells.size(); i++)
    {
        MapCell cell = map_cells[i];
        if (!cell.wall) continue;

        int dx;
        if (player->pos.x < cell.pos.x)
            dx = cell.pos.x - player->pos.x;
        else if (player->pos.x > cell.pos.x + cell.size.x)
            dx = player->pos.x - (cell.pos.x + cell.size.x);
        else
        {
            dx = 0;
        }
        
        int dy;
        if (player->pos.y < cell.pos.y)
            dy = cell.pos.y - player->pos.y;
        else if (player->pos.y > cell.pos.y + cell.size.y)
            dy = player->pos.y - (cell.pos.y + cell.size.y);
        else
        {
            dy = 0;
        }

        if (abs(dx) < player->radius && abs(dy) < player->radius)
            return true;
    }

    return false;
}

void SolvePlayerCollision()
{

}