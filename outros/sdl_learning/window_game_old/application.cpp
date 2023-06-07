#include <iostream>
#include <SDL2/SDL.h>
#include "application.hpp"
#include <math.h>
#include "collision.hpp"
#include "window.hpp"

void drawCircle(SDL_Renderer *renderer, int centerX, int centerY, int radius, int width = 1)
{
    int amount = 360 * radius / 50;
    float rate = M_PI / (float)amount;
    for (float angle = 0; angle < 2 * M_PI; angle += rate)
    {
        if (width > 1)
        {
            for (int r = -width / 2; r <= width / 2; r++)
            {
                int newRadius = radius + r;
                int x = centerX + cos(angle) * newRadius;
                int y = centerY + sin(angle) * newRadius;

                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
        else
        {
            int x = centerX + cos(angle) * radius;
            int y = centerY + sin(angle) * radius;

            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

Application::Application(int window_width, int window_height, int _window_count)
{
    // Initialize
    if (!SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error initializing video: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    // Create all windows
    // window_count = _window_count;
    // for (int i = 0; i < window_count; i++)
    // {
    window = SDL_CreateWindow(
        "Window Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        window_width,
        window_height,
        0);
    if (!window)
    {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
    {
        std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    window_surface = SDL_GetWindowSurface(window);
    if (!window_surface)
    {
        std::cout << "Error getting window surface: " << SDL_GetError() << std::endl;
        exit(-1);
    }
    // }

    // Get screen resolution
    SDL_DisplayMode mode;
    if (SDL_GetDesktopDisplayMode(0, &mode) != 0)
    {
        std::cout << "Error getting screen size: " << SDL_GetError() << std::endl;
        exit(-1);
    }
    std::cout << "Screen resolution: " << mode.w << "x" << mode.h << std::endl;

    // Set sizes
    window_size = Vec2{window_width, window_height};
    screen_size = Vec2{mode.w, mode.h};

    // Set colors
    floor_color = {200, 200, 200, SDL_ALPHA_OPAQUE};
    wall_color = {0, 0, 0, SDL_ALPHA_OPAQUE};
    player_color = {50, 50, 50, SDL_ALPHA_OPAQUE};

    // Create map
    map = "#################";
    map_size.x = map.length();
    map += "#..#.........#..#";
    map += "#..########..#..#";
    map += "#..#...#..#..#..#";
    map += "#..#...#..#..#..#";
    map += "#......#..#..#..#";
    map += "#..#####..#..#..#";
    map += "#.......P.......#";
    map += "#...............#";
    map += "#################";

    map_size.y = map.length() / map_size.x;
    cell_size = Vec2{screen_size.x / map_size.x, screen_size.y / map_size.y};

    // Check if map is valid
    if (map.length() != map_size.x * map_size.y)
    {
        std::cout << "Invalid map: all rows must be of equal size." << std::endl;
        exit(-1);
    }

    // Find start_x and start_y for player
    int idx = map.find('P');
    if (idx == std::string::npos)
    {
        std::cout << "Player is not on the map. Add a \"P\" on the map to mark where the player spawns" << std::endl;
        exit(-1);
    }
    int map_y = idx / map_size.x;
    int map_x = idx - map_y * map_size.x;

    // Convert to screen coordinates
    int start_x = (float)map_x / map_size.x * screen_size.x;
    int start_y = (float)map_y / map_size.y * screen_size.y;

    // Create player
    player = Player(start_x + cell_size.x / 2, start_y + cell_size.y / 2);

    // Create list of map rects
    map_cells = std::vector<MapCell>();
    for (int j = 0; j < map_size.y; j++)
    {
        int y = (float)j / map_size.y * screen_size.y;
        for (int i = 0; i < map_size.x; i++)
        {
            MapCell cell;
            cell.pos.x = (float)i / map_size.x * screen_size.x;
            cell.pos.y = y;
            cell.size.x = cell_size.x + 1;
            cell.size.y = cell_size.y + 1;
            cell.wall = map[j * map_size.x + i] == '#';

            map_cells.push_back(cell);
        }
    }
}

Application::~Application()
{
    SDL_FreeSurface(window_surface);
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

    case SDLK_f:
        FocusAll();
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

void Application::HandleScroll(int y_scroll)
{
    if (focused_window_idx == -1)
        return;

    // Get current size and position
    Vec2 current_size, pos;
    SDL_GetWindowSize(window, &current_size.x, &current_size.y);
    SDL_GetWindowPosition(window, &pos.x, &pos.y);

    // Change
    int change = -y_scroll * inc;
    current_size.x = SDL_clamp(current_size.x + change, 0, screen_size.x);
    current_size.y = SDL_clamp(current_size.y + change, 0, screen_size.y);
    pos.x = SDL_clamp(pos.x - change / 2, 0, screen_size.x);
    pos.y = SDL_clamp(pos.y - change / 2, 0, screen_size.y);

    // Apply new
    SDL_SetWindowSize(window, current_size.x, current_size.y);
    SDL_SetWindowPosition(window, pos.x, pos.y);

    // window_size.x = SDL_clamp(window_size.x - event.wheel.y * inc, 0, screen_size.x);
    // window_size.y = SDL_clamp(window_size.y - event.wheel.y * inc, 0, screen_size.y);
}

void Application::HandleWindowEvent(SDL_WindowEvent w_event)
{
    switch (w_event.event)
    {
    case SDL_WINDOWEVENT_SHOWN:
        if (debug_window_events)
            SDL_Log("IWindow %d shown", w_event.windowID);
        break;
    case SDL_WINDOWEVENT_HIDDEN:
        if (debug_window_events)
            SDL_Log("IWindow %d hidden", w_event.windowID);
        break;
    case SDL_WINDOWEVENT_MOVED:
        if (debug_window_events)
            SDL_Log("IWindow %d moved to %d,%d",
                    w_event.windowID, w_event.data1,
                    w_event.data2);
        break;
    case SDL_WINDOWEVENT_RESIZED:
        if (debug_window_events)
            SDL_Log("IWindow %d resized to %dx%d",
                    w_event.windowID, w_event.data1,
                    w_event.data2);
        break;
    case SDL_WINDOWEVENT_SIZE_CHANGED:
        if (debug_window_events)
            SDL_Log("IWindow %d size changed to %dx%d",
                    w_event.windowID, w_event.data1,
                    w_event.data2);
        break;
    case SDL_WINDOWEVENT_MINIMIZED:
        if (debug_window_events)
            SDL_Log("IWindow %d minimized", w_event.windowID);
        break;
    case SDL_WINDOWEVENT_MAXIMIZED:
        if (debug_window_events)
            SDL_Log("IWindow %d maximized", w_event.windowID);
        break;
    case SDL_WINDOWEVENT_RESTORED:
        if (debug_window_events)
            SDL_Log("IWindow %d restored", w_event.windowID);
        break;
    case SDL_WINDOWEVENT_ENTER:
        focused_window_idx = w_event.windowID - 1;
        if (debug_window_events)
            SDL_Log("Mouse entered window %d",
                    w_event.windowID);
        break;
    case SDL_WINDOWEVENT_LEAVE:
        focused_window_idx = -1;
        if (debug_window_events)
            SDL_Log("Mouse left window %d", w_event.windowID);
        break;
    case SDL_WINDOWEVENT_FOCUS_GAINED:
        if (debug_window_events)
            SDL_Log("IWindow %d gained keyboard focus",
                    w_event.windowID);
        break;
    case SDL_WINDOWEVENT_FOCUS_LOST:
        if (debug_window_events)
            SDL_Log("IWindow %d lost keyboard focus",
                    w_event.windowID);
        break;
    case SDL_WINDOWEVENT_CLOSE:
        if (debug_window_events)
            SDL_Log("IWindow %d closed", w_event.windowID);
        break;
#if SDL_VERSION_ATLEAST(2, 0, 5)
    case SDL_WINDOWEVENT_TAKE_FOCUS:
        if (debug_window_events)
            SDL_Log("IWindow %d is offered a focus", w_event.windowID);
        break;
    case SDL_WINDOWEVENT_HIT_TEST:
        if (debug_window_events)
            SDL_Log("IWindow %d has a special hit test", w_event.windowID);
        break;
#endif
    }
}

void Application::HandleEvents()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            HandleKeyDown(event.key.keysym.sym);
            break;
        case SDL_KEYUP:
            HandleKeyUp(event.key.keysym.sym);
            break;
        case SDL_MOUSEWHEEL:
            HandleScroll(event.wheel.y);
            break;
        case SDL_WINDOWEVENT:
            HandleWindowEvent(event.window);
            break;
        }
    }
}

void Application::ApplyWindowOffset(int window_idx, int *x, int *y)
{
    int window_x, window_y;
    SDL_GetWindowPosition(window, &window_x, &window_y);

    *x -= window_x;
    *y -= window_y;

    // *x -= window_pos.x;
    // *y -= window_pos.y;
}

void Application::FocusAll()
{
    // for (int i = 0; i < window_count; i++)
    // {
    //     SDL_ShowWindow(window);
    // }
}

void Application::update()
{
    // Update player
    player.update(pressedKeys.up - pressedKeys.down, pressedKeys.right - pressedKeys.left, screen_size.x, screen_size.y);

    // Check if window is being grabbed

    // Calculate window pos based on player position
    window_pos.x = SDL_clamp(player.pos.x - window_size.x / 2, 0, screen_size.x - window_size.x);
    window_pos.y = SDL_clamp(player.pos.y - window_size.y / 2, 0, screen_size.y - window_size.y);

    SDL_SetWindowPosition(window, window_pos.x, window_pos.y);
    SDL_SetWindowSize(window, window_size.x, window_size.y);
    SDL_Delay(1000 / 60);
}

void Application::draw()
{
    SDL_Rect rect;
    // for (int i = 0; i < window_count; i++)
    // {
    int i = 0;
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    // Draw map
    for (auto const &map_cell : map_cells)
    {
        if (map_cell.wall)
            SDL_SetRenderDrawColor(renderer, wall_color.r, wall_color.g, wall_color.b, wall_color.a);
        else
            SDL_SetRenderDrawColor(renderer, floor_color.r, floor_color.g, floor_color.b, floor_color.a);

        rect.x = map_cell.pos.x;
        rect.y = map_cell.pos.y;
        rect.w = map_cell.size.x;
        rect.h = map_cell.size.y;
        ApplyWindowOffset(i, &rect.x, &rect.y);
        SDL_RenderFillRect(renderer, &rect);
    }

    if (PlayerCollides(&player, map_cells))
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    else
        SDL_SetRenderDrawColor(renderer, player_color.r, player_color.g, player_color.b, player_color.a);
    // Draw player
    int player_x = player.pos.x, player_y = player.pos.y;
    ApplyWindowOffset(i, &player_x, &player_y);
    drawCircle(renderer, player_x, player_y, player.radius, 5);

    // Get look point
    int front_x = player.pos.x + cos(player.angle / 180 * M_PI) * player.radius;
    int front_y = player.pos.y + sin(player.angle / 180 * M_PI) * player.radius;
    ApplyWindowOffset(i, &front_x, &front_y);
    SDL_RenderDrawLine(renderer, player_x, player_y, front_x, front_y);

    // Render
    SDL_RenderPresent(renderer);
    // }F
}

void Application::loop()
{
    window_pos.x = 0;
    window_pos.y = 0;
    inc = 10;
    pressedKeys.left = pressedKeys.right = pressedKeys.up = pressedKeys.down = 0;
    while (running)
    {
        HandleEvents();
        update();
        draw();
    }
}