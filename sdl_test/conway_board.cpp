#include "conway_board.hpp"

ConwayBoard::ConwayBoard(int _width, int _height) {
    // Set width and height values
    width = _width;
    height = _height;

    // Init array
    int size = width * height;
    board = new int[_width];
    for (int i = 0; i < size; i++) {
        board[i] = 0;
    }
}

ConwayBoard::~ConwayBoard() {
    delete[] board;
}

int ConwayBoard::GetIndexFromCoord(int x, int y) {
    return y * width + x;
}

/**
 * Retorna 8 valores na lista
*/
void ConwayBoard::GetNeighbors(int x, int y, int *result_array) {
    result_array = new int[8];
    int i = 0;
    for (int nx = -1; nx <= 1; nx ++) {
        for (int ny = -1; ny <= 1; ny++) {
            // Get new coord
            int dx = x + nx;
            int dy = y + ny;

            // Check if out of borders
            if (dx < 0 or dx > width) return;
            if (dy < 0 or dy > height) return;

            // Get neighbors
            int idx = ConwayBoard::GetIndexFromCoord(dx, dy);

            // Add neighbor value to list
            result_array[i] = board[idx];
            i++;
        }
    }
}

void ConwayBoard::update() {
    // If cell == 1 and (living_neighbors < 2 or living_neighbors > 3) then cell = 0
    // If cell == 0 and living_neighbors == 3 then cell = 1
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            int[8] neighbors = ConwayBoard::getNeighbors(x, y, NULL);
        }
    }
}