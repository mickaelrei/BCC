#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "vec2.hpp"

class IWindow
{
    public:
        IWindow(int x = 0, int y = 0, int width = 300, int height = 300, std::string title = "IWindow");
        ~IWindow();

        // Handlers
        void HandleEvent(SDL_Event e);

        // Show content
        void render();

        // IWindow focus
        void focus();
        bool HasFocus();
        bool hasKeyboardFocus();
        bool isShown();

        // Converting between coordinate systems
        Vec2 ToScreenCoordinate(Vec2 window_pos);
        Vec2 ToWindowCoordinate(Vec2 screen_pos);
    private:
        // IWindow size
        Vec2 size;

        // IWindow data
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Surface* surface;
        int windowID;

        // IWindow focus
		bool mouseFocus;
		bool keyboardFocus;
		bool shown;
};

/*
IWindow
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