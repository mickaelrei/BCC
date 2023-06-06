#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "snake.hpp"
#include "food.hpp"

class Application
{
    public:
        Application(int window_width = 600, int window_height = 600, int _cols = 30, int _rows = 30, bool _borders = false, int food_count = 2);
        ~Application();
        void HandleKeyDown(SDL_Keycode keycode);
        void loop();
        SDL_Color background_color, snake_color, food_color, line_color;
        bool draw_lines = true;
    private:
        Vec2 ToScreenCoordinates(Vec2 pos);
        Vec2 RandomPoint();
        void update();
        void draw();
        void CheckEat();
        void AddFood();
        Vec2 cell_size;
        Snake snake;
        std::vector<Food> foods;
        int width, height, cols, rows;
        SDL_Window *window;
        SDL_Surface *window_surface;
        SDL_Renderer *renderer;
        bool running = true, dead = false, borders, changed_direction;
};