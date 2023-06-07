#include <iostream>
#include <SDL2/SDL.h>
#include <sstream>
#include <math.h>
#include "application.hpp"
#include "../window/window.hpp"

Application::Application(int window_width, int window_height, int _window_count)
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

    current_map.size.y = current_map.info.length() / current_map.size.x;

    init();

    // Create all windows
    int padding = 30;
    int _width = (screen_size.x - padding * _window_count) / _window_count;
    int y = 0;
    windows = std::vector<Window>(_window_count, Window());
    for (int i = 0; i < _window_count; i++)
    {
        std::stringstream title;
        title << "Window " << i;

        int x = i * (_width + padding);

        windows[i].init(
            screen_size,
            &current_map,
            current_map.wall_color,
            current_map.floor_color,
            x,
            y,
            _width,
            screen_size.y,
            // screen_size.x / 2 - window_width / 2,
            // screen_size.y / 2 - window_height / 2,
            // window_width,
            // window_height,
            title.str()
        );
    }
}

Application::Application(rapidjson::Document& config)
{
    // Assert config info
    assert(config["map"].IsArray());
    assert(config["windows"].IsArray());

    // Load map from config
    current_map.info = "";
    for (rapidjson::SizeType i = 0; i < config["map"].Size(); i++)
    {
        current_map.info += config["map"][i].GetString();
    }

    // Set map size
    current_map.size.x = strlen(config["map"][0].GetString());
    current_map.size.y = strlen(current_map.info.c_str()) / current_map.size.x;

    init();

    // Create windows based on config
    windows = std::vector<Window>(config["windows"].Size(), Window());
    for (rapidjson::SizeType i = 0; i < config["windows"].Size(); i++)
    {
        std::stringstream title;
        title << "Window " << i;

        const rapidjson::Value& window_json = config["windows"][i];

        // Check if colors exists
        SDL_Color wall_color, floor_color;
        if (window_json.HasMember("wall_color"))
            wall_color = {
                window_json["wall_color"][0].GetInt(),
                window_json["wall_color"][1].GetInt(),
                window_json["wall_color"][2].GetInt(),
                SDL_ALPHA_OPAQUE
            };
        else
            wall_color = {0, 0, 0, SDL_ALPHA_OPAQUE};

        if (window_json.HasMember("floor_color"))
            floor_color = {
                window_json["floor_color"][0].GetInt(),
                window_json["floor_color"][1].GetInt(),
                window_json["floor_color"][2].GetInt(),
                SDL_ALPHA_OPAQUE
            };
        else
            floor_color = {200, 200, 200, SDL_ALPHA_OPAQUE};

        windows[i].init(
            screen_size,
            current_map,
            wall_color,
            floor_color,
            window_json["x"].GetInt(),
            window_json["y"].GetInt(),
            window_json["width"].GetInt(),
            window_json["height"].GetInt(),
            title.str()
        );
    }
}

void Application::init()
{
    // Initialize
    if (!SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error initializing video: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    // Get screen resolution
    SDL_DisplayMode mode;
    if (SDL_GetDesktopDisplayMode(0, &mode) != 0)
    {
        std::cout << "Error getting screen size: " << SDL_GetError() << std::endl;
        exit(-1);
    }
    std::cout << "Screen resolution: " << mode.w << "x" << mode.h << std::endl;
    
    // Set sizes
    screen_size = Vec2i{mode.w, mode.h};

    // Set colors
    current_map.floor_color = {200, 200, 200, SDL_ALPHA_OPAQUE};
    current_map.wall_color = {0, 0, 0, SDL_ALPHA_OPAQUE};

    cell_size = Vec2i{screen_size.x / current_map.size.x, screen_size.y / current_map.size.y};

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
    int start_x = (float)map_x / current_map.size.x * screen_size.x;
    int start_y = (float)map_y / current_map.size.y * screen_size.y;

    // Create player
    player = Player(&current_map, start_x + cell_size.x / 2, start_y + cell_size.y / 2, -90, 15);

    // Create list of map rects
    current_map.cells = std::vector<SDL_Rect>();
    for (int j = 0; j < current_map.size.y; j++)
    {
        int y = (float)j / current_map.size.y * screen_size.y;
        for (int i = 0; i < current_map.size.x; i++)
        {
            SDL_Rect cell;
            cell.x = (float)i / current_map.size.x * screen_size.x;
            cell.y = y;
            cell.w = cell_size.x + 1;
            cell.h = cell_size.y + 1;

            current_map.cells.push_back(cell);
        }
    }
}

Application::~Application()
{
    for (int i = 0; i < windows.size(); i++)
    {
        printf("Destroying windows[%d]\n", i);
        windows[i].free();
    }
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
        case SDLK_0:
            windows[0].focus();
            break;
        case SDLK_1:
            windows[1].focus();
            break;
        case SDLK_2:
            windows[2].focus();
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

void Application::HandleScroll(SDL_Event e)
{
    for (int i = 0; i < windows.size(); i++)
    {
        windows[i].HandleScroll(e.wheel);
    }
}

void Application::HandleWindowEvent(SDL_WindowEvent w_event)
{
    for (int i = 0; i < windows.size(); i++)
    {
        windows[i].HandleWindowEvent(w_event);
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
            case SDL_WINDOWEVENT:
                HandleWindowEvent(event.window);
                break;
            case SDL_MOUSEWHEEL:
                HandleScroll(event);
                break;
        }
    }
}

void Application::update()
{
    // Update player
    player.update(pressedKeys.up - pressedKeys.down, pressedKeys.right - pressedKeys.left, screen_size.x, screen_size.y);
    SDL_Delay(1000 / 60);
}

void Application::draw()
{
    for (int i = 0; i < windows.size(); i++)
    {
        windows[i].render(current_map, player);
    }
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