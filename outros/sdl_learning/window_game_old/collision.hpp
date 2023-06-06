#pragma once

#include <iostream>
#include "player.hpp"
#include "vec2.hpp"
#include <vector>

// Checks for collision between player and map
bool PlayerCollides(Player* player, std::vector<MapCell> map_cells);

void SolvePlayerCollision();