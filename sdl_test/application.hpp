#pragma once

#include "conway_board.hpp"

class Application {
    public:
        Application(int _width, int _height, int board_cols, int board_rows);
        ~Application();
        void loop();
        void update();
        void draw();

    private:
        int width, height;
        SDL_Window *window;
        SDL_Surface *surface;
        SDL_Renderer *renderer;
        ConwayBoard board;
        double angle;
        int centerX, centerY;
};