#include "application.hpp"
#include <iostream>
#include <stdlib.h>

Application::Application(int _width, int _height, int _board_cols, int _board_rows) {
    // if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    //     std::cout << "Error initializing video: " << SDL_GetError() << std::endl;
    // }

    width = _width;
    height = _height;

    // window = SDL_CreateWindow(
    //     "SDL Window",
    //     SDL_WINDOWPOS_CENTERED,
    //     SDL_WINDOWPOS_CENTERED,
    //     width, height, 0);

    // surface = SDL_GetWindowSurface(window);
    // renderer = SDL_CreateRenderer(window, -1, 0);

    // Create conway board
    board = ConwayBoard(_board_cols, _board_rows);
}

Application::~Application() {
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Application::loop() {
    bool running = true;
    while (running) {
        // SDL_Event event;
 
        // // Events management
        // while (SDL_PollEvent(&event)) {
        //     switch (event.type) {
        //         case SDL_QUIT:
        //             // handling of close button
        //             running = false;
        //             break;
        //     }
        // }

        update();
        draw();
    }
}

void Application::update() {
    // Update conway board
    board.update();
    // SDL_Delay(1000 / 60);
}

void ClearScreen(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Application::draw() {
    system("cls");
    for (int y = 0; y < board.rows; y++) {
        for (int x = 0; x < board.cols; x++) {
            int state = board.GetCellAt(x, y);
            if (state == 1) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
        }

        std::cout << std::endl;
    }

    // ClearScreen(renderer);

    // // Draw all cells from board
    // for (int x = 0; x < board.cols; x++) {
    //     for (int y = 0; y < board.rows; y++) {
    //         // Get value and rect from cell
    //         int cellValue = board.GetCellAt(x, y);
    //         SDL_Rect cellRect = board.GetCellRect(width, height, x, y);

    //         // Change color based on cell value
    //         if (cellValue == 0) {
    //             SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    //         } else {
    //             SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    //         }

    //         // Render rect
    //         SDL_RenderFillRect(renderer, &cellRect);
    //     }
    // }

    // SDL_RenderPresent(renderer);
}