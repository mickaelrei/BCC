#include "application.hpp"
#include <iostream>
#include <stdlib.h>
#include <math.h>

Application::Application(int _width, int _height, int _board_cols, int _board_rows) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    }

    // Save width and height
    width = _width;
    height = _height;

    // Create window
    window = SDL_CreateWindow(
        "SDL Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width, height, 0);
    if (window == NULL) {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
    }

    // Get window surface
    surface = SDL_GetWindowSurface(window);
    if (surface == NULL) {
        std::cout << "Error getting window surface: " << SDL_GetError() << std::endl;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
        std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
    }

    // Create conway board
    board = ConwayBoard(_board_cols, _board_rows);

    angle = 0.0;
    centerX = width / 2;
    centerY = height / 2;
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
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_e:
                            std::cout << "Updating" << std:: endl;
                            update();
                    }
            }
        }

        // update();
        draw();
    }
}

void Application::update() {
    // Update conway board
    board.update();
    angle += .1;
    SDL_Delay(1000 / 3);
}

void ClearScreen(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Application::draw() {
    ClearScreen(renderer);

    // Draw all cells from board
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    for (int y = 0; y < board.rows; y++) {
        for (int x = 0; x < board.cols; x++) {
            // Get value and rect from cell
            int cellValue = board.GetCellAt(x, y);
            SDL_Rect cellRect = board.GetCellRect(width, height, x, y);

            // Paint only if cell is 1
            if (cellValue == 1) {
                SDL_RenderFillRect(renderer, &cellRect);
            }

            // std::cout << cellValue ? "#" : " ";
        }

        // std::cout << std::endl;
    }

    // for (int i = 0; i < 3; i++) {
    //      std::cout << std::endl;
    // }

    SDL_RenderPresent(renderer);
}