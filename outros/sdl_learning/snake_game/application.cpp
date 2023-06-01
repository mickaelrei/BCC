#include <iostream>
#include <SDL2/SDL.h>
#include "application.hpp"

Vector2 Application::ToScreenCoordinates(Vector2 pos)
{
    return Vector2(pos.x / cols * width, pos.y / rows * height);
}

Application::Application(int window_width, int window_height, int _cols, int _rows, bool _borders)
{
    // Initialize
    if (! SDL_Init( SDL_INIT_VIDEO ) < 0) {
        std::cout << "Error initializing video: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    window = SDL_CreateWindow(
        "Snake Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        window_width,
        window_height,
        0
    );
    if (!window) {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    window_surface = SDL_GetWindowSurface(window);
    if (!window_surface) {
        std::cout << "Error getting window surface: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    // Initialize variables related to screen
    width = window_width;
    height = window_height;
    cols = _cols;
    rows = _rows;
    borders = _borders;
    cell_size = Vector2(width / cols, height / rows);

    // Initialize colors
    background_color = {0, 0, 0, SDL_ALPHA_OPAQUE};
    snake_color = {0, 200, 0, SDL_ALPHA_OPAQUE};
    food_color = {200, 0, 0, SDL_ALPHA_OPAQUE};
    line_color = {100, 100, 100, SDL_ALPHA_OPAQUE};

    // Create snake
    std::cout << "Calling snake constructor\n";
    snake = Snake();
}

Application::~Application()
{
    SDL_FreeSurface(window_surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
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
            snake.ChangeDirection(Direction::North);
            break;

        case SDLK_DOWN:
        case SDLK_s:
            snake.ChangeDirection(Direction::South);
            break;

        case SDLK_LEFT:
        case SDLK_a:
            snake.ChangeDirection(Direction::West);
            break;

        case SDLK_RIGHT:
        case SDLK_d:
            snake.ChangeDirection(Direction::East);
            break;
    }
}

void Application::update()
{
    // snake.move();
    SDL_Delay(1000 / 5);
}

void Application::draw()
{
    // Clear
    SDL_SetRenderDrawColor(renderer, background_color.r, background_color.g, background_color.b, background_color.a);
    SDL_RenderClear(renderer);

    // Draw snake
    SDL_SetRenderDrawColor(renderer, snake_color.r, snake_color.g, snake_color.b, snake_color.a);
    for (int i = 0; i < snake.size; i++)
    {
        // Convert to screen coordinates
        Vector2 screen_pos = ToScreenCoordinates(snake.body[i]);

        // Draw rect
        SDL_Rect rect;
        rect.x = screen_pos.x;
        rect.y = screen_pos.y;
        rect.w = cell_size.x;
        rect.h = cell_size.y;
        SDL_RenderFillRect(renderer, &rect);
    }

    // Draw food
    // for (int i = 0; i < food_count; i++)
    // {

    // }

    // Draw lines
    SDL_SetRenderDrawColor(renderer, line_color.r, line_color.g, line_color.b, line_color.a);
    for (float j = 1; j < rows; j++)
    {
        // Horizontal
        int y = j / (float)rows * height;
        SDL_RenderDrawLine(renderer, 0, y, width, y);
    }

    for (float i = 1; i < cols; i++)
    {
        // Vertical
        int x = i / (float)cols * width;
        SDL_RenderDrawLine(renderer, x, 0, x, height);
    }

    // Render
    SDL_RenderPresent(renderer);
}

void Application::loop()
{
    SDL_Event e;
    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            switch (e.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    HandleKeyDown(e.key.keysym.sym);
                    break;
            }
        }

        update();
        draw();
    }
}