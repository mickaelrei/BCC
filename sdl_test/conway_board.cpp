#include "conway_board.hpp"
#include "SDL2/SDL.h"
#include <vector>
#include <iostream>
#include <cstdlib>

ConwayBoard::ConwayBoard() {

}

ConwayBoard::ConwayBoard(int _cols, int _rows) {
    // Set seed for RNG
    srand((unsigned) time(NULL));

    cols = _cols;
    rows = _rows;

    // Initialize current and previous_board boards
    int size = cols * rows;
    current_board = new int[size];
    next_board = new int[size];
    for (int i = 0; i < size; i++) {
        next_board[i] = 0;
        current_board[i] = rand() % 2;
    }
}

ConwayBoard::~ConwayBoard() {
    delete[] next_board;
    delete[] current_board;
}

int ConwayBoard::GetIndexFromCoord(int x, int y) {
    return y * cols + x;
}

int ConwayBoard::GetCellAt(int x, int y) {
    int idx = ConwayBoard::GetIndexFromCoord(x, y);
    return current_board[idx];
}

int ConwayBoard::CheckCell(int x, int y, int countAlive) {
    int idx = GetIndexFromCoord(x, y);
    if (current_board[idx] != 0) {
        if (countAlive == 2 or countAlive == 3) {
            return 1;
        }
        return 0;
    } else {
        if (countAlive == 3) {
            return 1;
        }
        return 0;
    }
}

std::vector<int> ConwayBoard::GetNeighbors(int x, int y) {
    // Create list of neighbors
    std::vector<int> neighbors = std::vector<int>();

    // Get all neighbors
    for (int nx = -1; nx <= 1; nx++) {
        for (int ny = -1; ny <= 1; ny++) {
            if (nx == 0 && ny == 0) continue;
            
            // Get new coord
            int dx = x + nx;
            int dy = y + ny;

            // Check if is out of borders
            if (dx < 0 || dx >= cols) continue;
            if (dy < 0 || dy >= rows) continue;

            // Get neighbor index
            int idx = ConwayBoard::GetIndexFromCoord(dx, dy);

            // Add neighbor value to list
            neighbors.push_back(current_board[idx]);
        }
    }

    return neighbors;
}

void ConwayBoard::update() {
    // Update next_board based on current_board
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            // Get neighbors
            std::vector<int> neighbors = ConwayBoard::GetNeighbors(x, y);

            // Get count of alive and dead neighbors
            int countAlive = 0;
            for (int i = 0; i < neighbors.size(); i++) {
                if (neighbors[i] != 0) {
                    countAlive++;
                }
            }

            // Get current state of this cell
            int cellIdx = ConwayBoard::GetIndexFromCoord(x, y);
            int cellState = current_board[cellIdx];

            // Check rules and update on next board
            next_board[cellIdx] = CheckCell(x, y, countAlive);
        }
    }

    // Move current_board into previous_board
    for (int i = 0; i < cols * rows; i++) {
        current_board[i] = next_board[i];
    }
}

SDL_Rect ConwayBoard::GetCellRect(int window_width, int window_height, int x, int y) {
    // Creates rect
    SDL_Rect rect;

    // Set width and height
    rect.w = window_width / cols;
    rect.h = window_height / rows;

    // Set position
    rect.x = x * rect.w;
    rect.y = y * rect.h;

    return rect;
}