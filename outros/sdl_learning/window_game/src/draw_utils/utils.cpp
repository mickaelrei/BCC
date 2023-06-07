#include "utils.hpp"

void DrawCircle(SDL_Renderer* renderer, int center_x, int center_y, int radius, int width)
{
    int amount = 360 * radius / 50;
    float rate = M_PI / (float)amount;
    for (float angle = 0; angle < 2 * M_PI; angle += rate)
    {
        if (width > 1)
        {
            for (int r = -width / 2; r <= width / 2; r++)
            {
                int newRadius = radius + r;
                int x = center_x + cos(angle) * newRadius;
                int y = center_y + sin(angle) * newRadius;

                SDL_RenderDrawPoint(renderer, x, y);
                
            }
        } else
        {
            int x = center_x + cos(angle) * radius;
            int y = center_y + sin(angle) * radius;

            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}