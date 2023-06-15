#pragma once

#include <vector>
#include <SDL2/SDL.h>

#include "../map/map.hpp"
#include "../player/player.hpp"

#include "../rapidjson/document.h"
#include "../rapidjson/filereadstream.h"

struct PressedKeys
{
    bool up, down, left, right;
};

class Application
{
    public:
        // Initialize
        Application(int window_width = 600, int window_height = 600);
        Application(rapidjson::Document& config);
        void init();

        // Destroy
        ~Application();

        // Main app loop
        void loop();
    private:
        // Update player movement and rotation
        void update();

        // Draw scene
        void draw();

        // Handle events
        void HandleKeyDown(SDL_Keycode keycode);
        void HandleKeyUp(SDL_Keycode keycode);
        void HandleEvents();

        // Window
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Surface* surface;
        SDL_Event event;

        // Current map
        bool running = true;
        Map current_map;
        int inc;

        // Sizes
        Vec2i window_size, cell_size;

        // Pressed keys for movement
        PressedKeys pressedKeys;

        // Player
        Player player;

        // Getting FPS
        int old_time = 0, mean_count = 3, current_count = 0;
        float current_total = 0;
};