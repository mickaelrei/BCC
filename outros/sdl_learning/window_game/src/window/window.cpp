#include <iostream>
#include <chrono>
#include <cmath>
#include "window.hpp"
#include "../draw_utils/utils.hpp"
#include "../application/application.hpp"

Window::Window()
{
    // Initialize non-existant window
	window = NULL;
	renderer = NULL;
    surface = NULL;

    windowID = 0;
    scroll_inc = 10;
}

void Window::init(Vec2i _screen_size, Map* map, SDL_Color wall_color, SDL_Color floor_color, int x, int y, int width, int height, std::string title)
{
    window = SDL_CreateWindow(
        title.c_str(),
        x,
        y,
        width,
        height,
        SDL_WINDOW_OPENGL
    );
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

    surface = SDL_GetWindowSurface(window);
    if (!surface)
    {
        std::cout << "Error getting window surface: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    // Set ID
    windowID = SDL_GetWindowID(window);
    scroll_inc = 10;

    // Set colors
    _wall_color = wall_color;
    _floor_color = floor_color;

    // Get sizes and position
    screen_size.x = _screen_size.x;
    screen_size.y = _screen_size.y;
    SDL_GetWindowSize(window, &size.x, &size.y);
    SDL_GetWindowPosition(window, &pos.x, &pos.y);
}

Window::~Window()
{
    free();
}

void Window::free()
{
    if (surface != NULL)
    {
        SDL_FreeSurface(surface);
        surface = NULL;
    }

    if (renderer != NULL)
    {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }

    if (window != NULL)
    {
        SDL_DestroyWindow(window);
        window = NULL;
    }
}

void Window::ApplyWindowOffset(int* x, int* y)
{
    *x -= pos.x;
    *y -= pos.y;
}

void Window::render(Map current_map, Player player)
{
    if (current_map.cells.size() == 0)
    {
        printf("No cells to draw\n");
        return;
    }

    // Update size and position members
    SDL_GetWindowPosition(window, &pos.x, &pos.y);
    SDL_GetWindowSize(window, &size.x, &size.y);        

    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    // Draw map
    SDL_Rect rect;
    for (int j = 0; j < current_map.size.y; j++)
    {
        for (int i = 0; i < current_map.size.x; i++)
        {
            if (current_map.info[j * current_map.size.x + i] == '#')
                SDL_SetRenderDrawColor(renderer, _wall_color.r, _wall_color.g, _wall_color.b, _wall_color.a);
            else
                SDL_SetRenderDrawColor(renderer, _floor_color.r, _floor_color.g, _floor_color.b, _floor_color.a);

            SDL_Rect cell = current_map.cells[j * current_map.size.x + i];
            rect.x = cell.x;
            rect.y = cell.y;
            rect.w = cell.w;
            rect.h = cell.h;
            ApplyWindowOffset(&rect.x, &rect.y);
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    SDL_SetRenderDrawColor(renderer, player.color.r, player.color.g, player.color.b, player.color.a);

    // Draw player
    int player_x = player.pos.x, player_y = player.pos.y;
    ApplyWindowOffset(&player_x, &player_y);
    DrawCircle(renderer, player_x, player_y, player.radius, 5);

    // Get look point
    int front_x = player.pos.x + cos(player.angle / 180 * M_PI) * player.radius;
    int front_y = player.pos.y + sin(player.angle / 180 * M_PI) * player.radius;
    ApplyWindowOffset(&front_x, &front_y);
    SDL_RenderDrawLine(renderer, player_x, player_y, front_x, front_y);

    // Render
    SDL_RenderPresent(renderer);
}

void Window::focus()
{
    SDL_RestoreWindow(window);
    SDL_RaiseWindow(window);
}

void Window::UpdateWindow()
{
    SDL_SetWindowPosition(window, pos.x, pos.y);
    SDL_SetWindowSize(window, size.x, size.y);
}

void Window::HandleScroll(SDL_MouseWheelEvent e)
{
    if (e.windowID != windowID) return;

    // Get current size and position
    Vec2i current_size;
    SDL_GetWindowSize(window, &current_size.x, &current_size.y);
    SDL_GetWindowPosition(window, &pos.x, &pos.y);

    // Change
    int change = -e.y * scroll_inc;
    current_size.x = SDL_clamp(current_size.x + change, 0, screen_size.x);
    current_size.y = SDL_clamp(current_size.y + change, 0, screen_size.y);
    pos.x = SDL_clamp(pos.x - change / 2, 0, screen_size.x);
    pos.y = SDL_clamp(pos.y - change / 2, 0, screen_size.y);

    // Apply new
    SDL_SetWindowSize(window, current_size.x, current_size.y);
    SDL_SetWindowPosition(window, pos.x, pos.y);
}

void Window::HandleWindowEvent(SDL_WindowEvent window_event)
{
	if (window_event.windowID != windowID) return;

    switch (window_event.event)
    {
        // Get new dimensions
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            size.x = window_event.data1;
            size.y = window_event.data2;
            break;

        // Mouse enter
        case SDL_WINDOWEVENT_ENTER:
            // mouseFocus = true;
            break;
        
        // Mouse exit
        case SDL_WINDOWEVENT_LEAVE:
            // mouseFocus = false;
            break;

        // Keyboard focus gained
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            // keyboardFocus = true;
            break;
        
        // Keyboard focus lost
        case SDL_WINDOWEVENT_FOCUS_LOST:
            // keyboardFocus = false;
            break;
        
        // Get new position
        case SDL_WINDOWEVENT_MOVED:
            pos.x = window_event.data1;
            pos.y = window_event.data2;
            break;
    }
}

Vec2i Window::ToScreenCoordinate(Vec2i window_pos)
{
    Vec2i screen_pos;

    return screen_pos;
}

Vec2i Window::ToWindowCoordinate(Vec2i screen_pos)
{
    Vec2i window_pos;

    return window_pos;
}