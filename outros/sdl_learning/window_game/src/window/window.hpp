#pragma once

#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include "../coordinates/coordinates.hpp"
#include "../map/map.hpp"
#include "../player/player.hpp"

class Window
{
    public:
        // Initialize
        Window();
        void init(Vec2i _screen_size, Map* map, SDL_Color wall_color, SDL_Color floor_color, int x = 0, int y = 0, int width = 300, int height = 300, std::string title = "Window");
        
        // Destroy
        ~Window();
        void free();

        // Handlers
        void HandleWindowEvent(SDL_WindowEvent window_event);
        void HandleScroll(SDL_MouseWheelEvent e);

        // Show content
        void render(Map current_map, Player player);

        // Window focus
        void focus();

        // Converting between coordinate systems
        Vec2i ToScreenCoordinate(Vec2i window_pos);
        Vec2i ToWindowCoordinate(Vec2i screen_pos);
        void ApplyWindowOffset(int* x, int* y);
    private:
        // Window coordinate
        Vec2i pos;
        Vec2i size;
        Vec2i screen_size;

        // Color data
        SDL_Color _wall_color, _floor_color;

        // Window data
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Surface* surface;
        int windowID;

        // Update window data
        void UpdatePosition();

        // Size scroll increment
        int scroll_inc;
};

/*
Window
Width, height
Renderer
Surface
HasFocus()
HasKeyboardFocus()
IsShown()
Focus()
Render()
ToScreenCoordinates(windowPos)
ToWindowCoordinates(screenPos)*/