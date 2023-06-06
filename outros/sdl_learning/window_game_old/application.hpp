#pragma once

#include <SDL2/SDL.h>
#include "vec2.hpp"
#include "player.hpp"
#include <vector>

struct PressedKeys {
    bool up, down, left, right;
};

class Application
{
    public:
        Application(int window_width = 300, int window_height = 300, int window_count = 5);
        ~Application();
        void loop();
        bool debug_window_events;
    private:
        void update();
        void draw();
        void HandleKeyDown(SDL_Keycode keycode);
        void HandleKeyUp(SDL_Keycode keycode);
        void HandleScroll(int y_scroll);
        void HandleWindowEvent(SDL_WindowEvent w_event);
        void HandleEvents();
        void ApplyWindowOffset(int window_idx, int *x, int *y);
        void FocusAll();
        std::vector<SDL_Window*> windows;
        std::vector<SDL_Surface*> window_surfaces;
        std::vector<SDL_Renderer*> renderers;
        int window_count;
        int focused_window_idx = 0;
        // SDL_Window *window;
        // SDL_Surface *window_surface;
        // SDL_Renderer *renderer;
        SDL_Event event;
        SDL_Color floor_color, wall_color, player_color; 
        std::string map;
        std::vector<MapCell> map_cells;
        bool running = true;
        int inc;
        Vec2 map_size, screen_size, window_size, cell_size, window_pos;
        PressedKeys pressedKeys;
        Player player;
};