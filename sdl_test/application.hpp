#pragma once

#include "SDL2/SDL.h"

class Application {
    public:
        Application(int width, int height);
        ~Application();
        void loop();
        void update();
        void draw();

    private:
        SDL_Window *window;
        SDL_Surface *surface;
        SDL_Renderer *renderer;
};