#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "snake.hpp"

class Application
{
    public:
        Application(int window_width = 600, int window_height = 600, int _cols = 10, int _rows = 10, bool _borders = false);
        ~Application();
        void HandleKeyDown(SDL_Keycode keycode);
        void loop();
        SDL_Color background_color, snake_color, food_color, line_color;
        bool draw_lines = true;
    private:
        Vector2 ToScreenCoordinates(Vector2 pos);
        void update();
        void draw();
        Vector2 cell_size;
        Snake snake;
        int width, height, cols, rows;
        SDL_Window *window;
        SDL_Surface *window_surface;
        SDL_Renderer *renderer;
        bool running = true, borders;
};