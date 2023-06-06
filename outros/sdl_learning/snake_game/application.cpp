#include <iostream>
#include <SDL2/SDL.h>
#include "application.hpp"
#include "vector2.hpp"

Vec2 Application::ToScreenCoordinates(Vec2 pos)
{
    int x = (int) ((float)pos.x / (float)cols * (float)width);
    int y = (int) ((float)pos.y / (float)rows * (float)height);

    return Vec2{x, y};
}

Vec2 Application::RandomPoint()
{
    int x = rand() % cols;
    int y = rand() % rows;

    return Vec2{x, y};
}

void Application::AddFood()
{
    // Sanity check to prevent infinite while loop
    if (snake.body.size() + foods.size() >= cols * rows)
    {
        printf("Cannot create another food.\n");
        return;
    }

    // Get random location
    Vec2 pos;

    // Keep checking if this position collides with a food or snake body
    bool valid = false;
    while (!valid)
    {
        pos = RandomPoint();
        valid = true;

        // Foods
        for (int j = 0; j < foods.size(); j++)
        {
            if (foods[j].pos.x == pos.x && foods[j].pos.y == pos.y)
            {
                valid = false;
                break;
            }
        }

        // Snake
        for (int j = 0; j < snake.body.size(); j++)
        {
            if (snake.body[j].x == pos.x && snake.body[j].y == pos.y)
            {
                valid = false;
                break;
            }
        }
    }

    // 1/10 chance of being a rare fruit, 1/100 chance of being a super rare fruit (50 grow_amount)
    Food new_food;
    int rand_num = rand();
    if (rand_num % 100 == 1)
    {
        new_food.color = {255, 192, 203};
        new_food.grow_amount = 50;
    }
    else if (rand_num % 10 == 1)
    {
        new_food.color = {200, 200, 0, SDL_ALPHA_OPAQUE};
        new_food.grow_amount = 2;
    } else
    {
        new_food.color = food_color;
        new_food.grow_amount = 1;
    }
    new_food.pos = pos;

    // Add to list
    foods.push_back(new_food);
}

Application::Application(int window_width, int window_height, int _cols, int _rows, bool _borders, int food_count)
{
    // Initialize
    if (! SDL_Init( SDL_INIT_VIDEO ) < 0)
    {
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

    // Initialize variables related to screen
    width = window_width;
    height = window_height;
    cols = _cols;
    rows = _rows;
    borders = _borders;
    cell_size = Vec2{width / cols, height / rows};

    // Initialize colors
    background_color = {0, 0, 0, SDL_ALPHA_OPAQUE};
    snake_color = {0, 200, 0, SDL_ALPHA_OPAQUE};
    food_color = {200, 0, 0, SDL_ALPHA_OPAQUE};
    line_color = {100, 100, 100, SDL_ALPHA_OPAQUE};

    // Create snake
    snake = Snake();

    // Create foods list
    foods = std::vector<Food>();
    for (int i = 0; i < food_count; i++)
    {
        AddFood();
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
            if (!changed_direction)
            {
                changed_direction = true;
                snake.ChangeDirection(Direction::North);
            }
            break;

        case SDLK_DOWN:
        case SDLK_s:
            if (!changed_direction)
            {
                changed_direction = true;
                snake.ChangeDirection(Direction::South);
            }
            break;

        case SDLK_LEFT:
        case SDLK_a:
            if (!changed_direction)
            {
                changed_direction = true;
                snake.ChangeDirection(Direction::West);
            }
            break;

        case SDLK_RIGHT:
        case SDLK_d:
            if (!changed_direction)
            {
                changed_direction = true;
                snake.ChangeDirection(Direction::East);
            }
            break;
        case SDLK_f:
            std::cout << "Current snake size: " << snake.body.size() << std::endl;
    }
}

void Application::update()
{
    dead = snake.CheckDead(borders, cols, rows);
    if (dead)
    {
        return;
    }
    
    snake.update(borders, cols, rows);
    CheckEat();
    SDL_Delay(1000 / 15);
}

void Application::CheckEat()
{
    // Check for all foods
    for (int i = 0; i < foods.size(); i++)
    {
        if (foods[i].pos.x == snake.body[0].x && foods[i].pos.y == snake.body[0].y)
        {
            // Tell snake to grow
            snake.grow(foods[i].grow_amount);

            // Delete this food from list
            foods.erase(foods.begin() + i);

            // Add another food
            AddFood();

            // Because there won't be more than 1 food at the same place, break after finding a hit
            break;
        }
    }
}

void Application::draw()
{
    SDL_Rect rect;

    // Clear
    SDL_SetRenderDrawColor(renderer, background_color.r, background_color.g, background_color.b, background_color.a);
    SDL_RenderClear(renderer);

    // Draw food
    for (int i = 0; i < foods.size(); i++)
    {
        // Get screen coordinates
        Vec2 screen_pos = ToScreenCoordinates(foods[i].pos);

        // Draw rect
        rect.x = screen_pos.x;
        rect.y = screen_pos.y;
        rect.w = cell_size.x;
        rect.h = cell_size.y;
        SDL_SetRenderDrawColor(renderer, foods[i].color.r, foods[i].color.g, foods[i].color.b, foods[i].color.a);
        SDL_RenderFillRect(renderer, &rect);
    }

    // Draw snake
    SDL_SetRenderDrawColor(renderer, snake_color.r, snake_color.g, snake_color.b, snake_color.a);
    for (int i = 0; i < snake.body.size(); i++)
    {
        // Convert to screen coordinates
        Vec2 screen_pos = ToScreenCoordinates(snake.body[i]);

        // Draw rect
        rect.x = screen_pos.x;
        rect.y = screen_pos.y;
        rect.w = cell_size.x;
        rect.h = cell_size.y;
        SDL_RenderFillRect(renderer, &rect);
    }

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
        changed_direction = false;
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


        if (dead)
        {
            std::string end_message = "You got " + std::to_string(snake.body.size() - snake.start_size) + " points!";
            running = false;
            SDL_ShowSimpleMessageBox(
                SDL_MESSAGEBOX_INFORMATION,
                "Game over",
                end_message.c_str(),
                window
            );
        } else
        {
            update();
            draw();
        }
    }
}