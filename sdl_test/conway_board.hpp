#pragma once

class ConwayBoard {
    public:
        ConwayBoard(int _width, int _height);
        ~ConwayBoard();

        void update();
    private:
        int width;
        int height;
        int *board;
        int GetIndexFromCoord(int x, int y);
        void GetNeighbors(int x, int y, int *result_array);
}