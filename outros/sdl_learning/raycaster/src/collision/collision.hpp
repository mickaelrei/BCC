#pragma once

#include <iostream>
#include <vector>
#include "../map/map.hpp"

// Checks for collision between player and map
bool PlayerCollides(Vec2f* player_pos, int player_radius, Map* map);