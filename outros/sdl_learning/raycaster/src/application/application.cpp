#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "application.hpp"

void DrawCircle(SDL_Renderer* renderer, int center_x, int center_y, int radius, int width=1)
{
    // Check if circle is out of bounds
    if (center_x < radius || center_y < radius ||
        center_x > 3000 || center_y > 3000)
    {
        return;
    }

    int amount = 360 * radius / 50;
    float rate = M_PI / (float)amount;
    for (float angle = 0; angle < 2 * M_PI; angle += rate)
    {
        if (width > 1)
        {
            for (int r = -width / 2; r <= width / 2; r++)
            {
                int newRadius = radius + r;
                int x = center_x + cos(angle) * newRadius;
                int y = center_y + sin(angle) * newRadius;

                SDL_RenderDrawPoint(renderer, x, y);
                
            }
        } else
        {
            int x = center_x + cos(angle) * radius;
            int y = center_y + sin(angle) * radius;

            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

Vec2i TileCoords(Vec2i cell_size, int x, int y)
{
    return Vec2i{x / cell_size.x, y / cell_size.y};
}

std::vector<Vec2i> Raycast(Map map, Vec2i ray_pos, Vec2f ray_dir)
{
    std::vector<Vec2i> points;
    Vec2i cell_size = {map.cells[0].w, map.cells[0].h};

    Vec2i dir_sign;
    dir_sign.x = ray_dir.x > 0 ? 1 : -1;
    dir_sign.y = ray_dir.y > 0 ? 1 : -1;

    Vec2i tile_offset;
    tile_offset.x = (ray_dir.x > 0 ? 1 : 0);
    tile_offset.y = (ray_dir.y > 0 ? 1 : 0);

    Vec2i curr = {ray_pos.x, ray_pos.y};
    Vec2i tile = TileCoords(cell_size, curr.x, curr.y);
    int t = 0;

    Vec2i dt;
    dt.x = ((tile.x + tile_offset.x) * cell_size.x - curr.x) / ray_dir.x;
    dt.y = ((tile.y + tile_offset.y) * cell_size.y - curr.y) / ray_dir.y;

    if (ray_dir.x*ray_dir.x + ray_dir.y*ray_dir.y > 0)
    {
        while (tile.x > 0 && tile.x < map.size.x && tile.y > 0 && tile.y < map.size.y)
        {
            points.push_back(Vec2i{(int)(ray_pos.x + ray_dir.x * t), (int)(ray_pos.y + ray_dir.y * t)});

            if (dt.x < dt.y)
            {
                tile.x += dir_sign.x;
                float _dt = dt.x;
                t += _dt;
                dt.x = dt.x + dir_sign.x * cell_size.x / ray_dir.x - _dt;
                dt.y -= _dt;
            } else
            {
                tile.y += dir_sign.y;
                float _dt = dt.y;
                t += _dt;
                dt.x -= _dt;
                dt.y = dt.y + dir_sign.y * cell_size.y / ray_dir.y - _dt;
            }
        }
    }

    return points;
}

double RaycastDDA(Map map, Vec2i ray_pos, Vec2f ray_dir)
{
    Vec2i cell_size = Vec2i{map.cells[0].w, map.cells[0].h};
    int posX = ray_pos.x / cell_size.x;
    int posY = ray_pos.y / cell_size.y;
    printf("At (%d, %d)\n", posX, posY);

    int mapX = posX;
    int mapY = posY;

    double sideDistX, sideDistY;

    double deltaDistX = ray_dir.x == 0 ? 1e30 : std::abs(1 / ray_dir.x);
    double deltaDistY = ray_dir.y == 0 ? 1e30 : std::abs(1 / ray_dir.y);
    double perpWallDist;

    int stepX, stepY;
    int hit = 0, side;

    //calculate step and initial sideDist
    if (ray_dir.x < 0)
    {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
    }
    else
    {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
    }
    if (ray_dir.y < 0)
    {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
    }
    else
    {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
    }
    
    //perform DDA
    while (hit == 0)
    {
        //jump to next map square, either in x-direction, or in y-direction
        if (sideDistX < sideDistY)
        {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
        }
        else
        {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
        }

        //Check if ray has hit a wall
        if (map.info[mapY * map.size.x + mapX] == '#') 
        {
            printf("Rect at (%d, %d) is a wall\n", mapX, mapY);
            hit = 1;
        }
    } 

    //Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
    if(side == 0) perpWallDist = (sideDistX - deltaDistX);
    else          perpWallDist = (sideDistY - deltaDistY);

    // printf("SideDistX: %.2f, sideDistY: %.2f\n", sideDistX, sideDistY);
    return perpWallDist;
}

Application::Application(int window_width, int window_height)
{
    // Create default map
    current_map.info  = "#################";
    current_map.size.x = current_map.info.length();
    current_map.info += "#..#.........#..#";
    current_map.info += "#..########..#..#";
    current_map.info += "#..#...#..#..#..#";
    current_map.info += "#..#...#..#..#..#";
    current_map.info += "#......#..#..#..#";
    current_map.info += "#..#####..#..#..#";
    current_map.info += "#.......P.......#";
    current_map.info += "#...............#";
    current_map.info += "#################";

    // Set map size
    current_map.size.y = current_map.info.length() / current_map.size.x;

    // Set window size
    window_size.x = window_width;
    window_size.y = window_height;

    init();
}

Application::Application(rapidjson::Document& config)
{
    // Assert config info
    assert(config.HasMember("map"));
    assert(config.HasMember("window_width"));
    assert(config.HasMember("window_height"));
    assert(config["map"].IsArray());
    assert(config["window_width"].IsInt());
    assert(config["window_height"].IsInt());

    // Load map from config
    current_map.info = "";
    for (rapidjson::SizeType i = 0; i < config["map"].Size(); i++)
    {
        current_map.info += config["map"][i].GetString();
    }

    // Set map size
    current_map.size.x = strlen(config["map"][0].GetString());
    current_map.size.y = strlen(current_map.info.c_str()) / current_map.size.x;

    // Get window size
    window_size.x = config["window_width"].GetInt();
    window_size.y = config["window_height"].GetInt();
    init();
}

void Application::init()
{
    // Initialize
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error initializing video: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    // Get window, renderer and surface
    window = SDL_CreateWindow(
        "Raycaster",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        window_size.x,
        window_size.y,
        SDL_WINDOW_SHOWN
    );
    if (window == NULL)
    {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL)
    {
        std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    surface = SDL_GetWindowSurface(window);
    if (surface == NULL)
    {
        std::cout << "Error getting window surface: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    // Set colors
    current_map.floor_color = {200, 200, 200, SDL_ALPHA_OPAQUE};
    current_map.wall_color = {0, 0, 0, SDL_ALPHA_OPAQUE};

    cell_size = Vec2i{window_size.x / current_map.size.x, window_size.y / current_map.size.y};

    // Check if map is valid
    if (current_map.info.length() != current_map.size.x * current_map.size.y)
    {
        std::cout << "Invalid map: all rows must be of equal size." << std::endl;
        exit(-1);
    }

    // Find start_x and start_y for player
    int idx = current_map.info.find('P');
    if (idx == std::string::npos)
    {
        std::cout << "Player is not on the map. Add a \"P\" on the map to mark where the player spawns" << std::endl;
        exit(-1);
    }
    int map_y = idx / current_map.size.x;
    int map_x = idx - map_y * current_map.size.x;

    // Convert to screen coordinates
    int start_x = (float)map_x / current_map.size.x * window_size.x;
    int start_y = (float)map_y / current_map.size.y * window_size.y;

    // Create player
    player = Player(&current_map, start_x + cell_size.x / 2, start_y + cell_size.y / 2, -90, 15);

    // Create list of map rects
    current_map.cells = std::vector<SDL_Rect>();
    for (int j = 0; j < current_map.size.y; j++)
    {
        int y = (float)j / current_map.size.y * window_size.y;
        for (int i = 0; i < current_map.size.x; i++)
        {
            SDL_Rect cell;
            cell.x = (float)i / current_map.size.x * window_size.x;
            cell.y = y;
            cell.w = cell_size.x + 1;
            cell.h = cell_size.y + 1;

            current_map.cells.push_back(cell);
        }
    }
}

Application::~Application()
{
    SDL_FreeSurface(surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Application::HandleKeyDown(SDL_Keycode keycode)
{
    switch (keycode)
    {
        case SDLK_ESCAPE:
            running = false;
            break;

        case SDLK_UP:
        case SDLK_w:
            pressedKeys.up = 1;
            break;

        case SDLK_DOWN:
        case SDLK_s:
            pressedKeys.down = 1;
            break;

        case SDLK_LEFT:
        case SDLK_a:
            pressedKeys.left = 1;
            break;

        case SDLK_RIGHT:
        case SDLK_d:
            pressedKeys.right = 1;
            break;
    }
}

void Application::HandleKeyUp(SDL_Keycode keycode)
{
    switch (keycode)
    {
        case SDLK_ESCAPE:
            running = false;
            break;

        case SDLK_UP:
        case SDLK_w:
            pressedKeys.up = 0;
            break;

        case SDLK_DOWN:
        case SDLK_s:
            pressedKeys.down = 0;
            break;

        case SDLK_LEFT:
        case SDLK_a:
            pressedKeys.left = 0;
            break;

        case SDLK_RIGHT:
        case SDLK_d:
            pressedKeys.right = 0;
            break;
    }
}

void Application::HandleEvents()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                HandleKeyDown(event.key.keysym.sym);
                break;
            case SDL_KEYUP:
                HandleKeyUp(event.key.keysym.sym);
                break;
        }
    }
}

void Application::update()
{
    // Get FPS
    int new_time = SDL_GetTicks();
    if (current_count == mean_count)
    {
        float fps = 1000.f / (current_total / mean_count);
        // std::cout << "FPS: " << fps << std::endl;
        current_total = (float)(new_time - old_time);
        current_count = 1;
    } else
    {
        current_total += (float)(new_time - old_time);
        current_count ++;
    }

    old_time = new_time;
    
    // Update player
    player.update(pressedKeys.up - pressedKeys.down, pressedKeys.right - pressedKeys.left, window_size.x, window_size.y);

    SDL_Delay(1000 / 60);
}

void Application::draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    // Draw map
    SDL_Rect rect;
    for (int j = 0; j < current_map.size.y; j++)
    {
        for (int i = 0; i < current_map.size.x; i++)
        {
            if (current_map.info[j * current_map.size.x + i] == '#')
                SDL_SetRenderDrawColor(renderer, current_map.wall_color.r, current_map.wall_color.g, current_map.wall_color.b, current_map.wall_color.a);
            else
                SDL_SetRenderDrawColor(renderer, current_map.floor_color.r, current_map.floor_color.g, current_map.floor_color.b, current_map.floor_color.a);

            SDL_Rect cell = current_map.cells[j * current_map.size.x + i];
            rect.x = cell.x;
            rect.y = cell.y;
            rect.w = cell.w;
            rect.h = cell.h;
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    // Draw grid lines
    int draw_grid_lines = 1;
    if (draw_grid_lines)
    {
        SDL_SetRenderDrawColor(renderer, 0, 150, 0, SDL_ALPHA_OPAQUE);
        for (float i = 1; i < current_map.size.x; i++)
        {
            int x = i / (float)current_map.size.x * window_size.x;
            SDL_RenderDrawLine(renderer, x, 0, x, window_size.y);
        }

        for (float j = 1; j < current_map.size.y; j++)
        {
            int y = j / (float)current_map.size.y * window_size.y;
            SDL_RenderDrawLine(renderer, 0, y, window_size.x, y);
        }
    }

    SDL_SetRenderDrawColor(renderer, player.color.r, player.color.g, player.color.b, player.color.a);

    // Draw player
    int player_x = player.pos.x, player_y = player.pos.y;
    DrawCircle(renderer, player_x, player_y, player.radius, 5);

    // Get look point
    int front_x = player.pos.x + cos(player.angle / 180 * M_PI) * player.radius;
    int front_y = player.pos.y + sin(player.angle / 180 * M_PI) * player.radius;    
    SDL_RenderDrawLine(renderer, player_x, player_y, front_x, front_y);

    // Draw fov lines
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    int rays = 1, len = 500;
    float half_fov = player.fov / 2;
    float angle_step = player.fov / rays;
    float start_angle = player.angle - half_fov;
    for (int i = 0; i < rays; i++)
    {
        float angle = start_angle + angle_step * i;

        // Get X and Y for long ray
        float _cos = cosf(angle / 180 * M_PI);
        float _sin = sinf(angle / 180 * M_PI);
        float x = player.pos.x + _cos * len;
        float y = player.pos.y + _sin * len;

        // Draw line
        SDL_RenderDrawLine(renderer, player.pos.x, player.pos.y, (int)x, (int)y);

    }
    
    // Draw raycast points
    float _cos = cosf(player.angle / 180 * M_PI);
    float _sin = sinf(player.angle / 180 * M_PI);
    Vec2f ray_dir = Vec2f{_cos, _sin};
    Vec2i ray_pos = Vec2i{(int)player.pos.x, (int)player.pos.y};

    double dist = RaycastDDA(current_map, ray_pos, ray_dir);
    printf("Dist: %.2f\n", dist);
    int new_x = player.pos.x * _cos * dist * current_map.cells[0].w;
    int new_y = player.pos.y * _sin * dist * current_map.cells[0].h;
    DrawCircle(renderer, new_x, new_y, 5);

    // std::vector<Vec2i> points = Raycast(current_map, ray_pos, ray_dir);
    // for (auto& point : points)
    // {
    //     DrawCircle(renderer, point.x, point.y, 5);
    // }

    // Render
    SDL_RenderPresent(renderer);
}

void Application::loop()
{
    pressedKeys.left = pressedKeys.right = pressedKeys.up = pressedKeys.down = 0;
    while (running)
    {   
        HandleEvents();
        update();
        draw();
    }
}