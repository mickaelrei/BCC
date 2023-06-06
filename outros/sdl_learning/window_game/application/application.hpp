#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include "../coordinates/coordinates.hpp"
#include "../player/player.hpp"
#include "../window/window.hpp"

struct PressedKeys
{
    bool up, down, left, right;
};

class Application
{
    public:
        // Initialize
        Application(int window_width = 300, int window_height = 300, int window_count = 5);

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
        void HandleWindowEvent(SDL_WindowEvent w_event);
        void HandleScroll(SDL_Event e);
        void HandleEvents();

        // Apply offset
        void ApplyWindowOffset(int window_idx, int *x, int *y);

        // Windows
        std::vector<Window> windows;
        SDL_Event event;

        // Current map
        bool running = true;
        Map current_map;
        int inc;

        // Sizes
        Vec2 screen_size, cell_size;

        // Pressed keys for movement
        PressedKeys pressedKeys;

        // Player
        Player player;
};