#pragma once

#include <vector>
#include "SDL2/SDL.h"

class ConwayBoard {
    public:
        ConwayBoard();
        ConwayBoard(int _cols, int _rows);
        ~ConwayBoard();

        int cols, rows;
        void update();
        int GetCellAt(int x, int y);
        SDL_Rect GetCellRect(int window_width, int window_height, int x, int y);
        
    private:
        int* current_board;
        int* next_board;
        int GetIndexFromCoord(int x, int y);
        std::vector<int> GetNeighbors(int x, int y);
        int CheckCell(int x, int y, int countAlive);
};