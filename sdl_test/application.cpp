#include "application.hpp"
#include "SDL2/SDL.h"
#include <iostream>

Application::Application(int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Error initializing video: " << SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow(
        "SDL Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height, 0);

    surface = SDL_GetWindowSurface(window);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Application::~Application() {
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Application::loop() {
    bool running = true;
    while (running) {
        SDL_Event event;
 
        // Events management
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
 
            case SDL_QUIT:
                // handling of close button
                running = false;
                break;
            }
        }

        update();
        draw();
    }
}

void Application::update() {

}

void ClearScreen(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Application::draw() {
    SDL_Rect rect;
    rect.x = 15;
    rect.y = 15;
    rect.w = 50;
    rect.h = 50;

    ClearScreen(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
    // SDL_UpdateWindowSurface(window);
}