#pragma once

struct Vec2 {
    int x, y;
};

struct MapCell {
    Vec2 pos, size;
    bool wall;
};