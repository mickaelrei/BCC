#include <iostream>
#include "window.hpp"

IWindow::IWindow(int x, int y, int width, int height, std::string title)
{
    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
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

    surface = SDL_GetWindowSurface(window);
    if (!surface)
    {
        std::cout << "Error getting window surface: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    windowID = SDL_GetWindowID(window);
    mouseFocus = true;
    keyboardFocus = true;
    shown = true;
    SDL_GetWindowSize(window, &size.x, &size.y);
}

IWindow::~IWindow()
{
    SDL_FreeSurface(surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void IWindow::render()
{
    // Render map
}

void IWindow::HandleEvent(SDL_event e)
{
	if (!(e.type == SDL_WINDOWEVENT && e.window.windowID == mWindowID)) break;

    switch (e.window.event)
    {
        //IWindow appeared
        case SDL_WINDOWEVENT_SHOWN:
            shown = true;
            break;

        //IWindow disappeared
        case SDL_WINDOWEVENT_HIDDEN:
            shown = false;
            break;

        //Get new dimensions and repaint
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            width = e.window.data1;
            height = e.window.data2;
            break;

        //Repaint on expose
        case SDL_WINDOWEVENT_EXPOSED:
            break;

        //Mouse enter
        case SDL_WINDOWEVENT_ENTER:
            mouseFocus = true;
            break;
        
        //Mouse exit
        case SDL_WINDOWEVENT_LEAVE:
            mouseFocus = false;
            break;

        //Keyboard focus gained
        case SDL_WINDOWEVENT_FOCUS_GAINED:
        mKeyboardFocus = true;
        updateCaption = true;
        break;
        
        //Keyboard focus lost
        case SDL_WINDOWEVENT_FOCUS_LOST:
            keyboardFocus = false;
            break;

        //Hide on close
        case SDL_WINDOWEVENT_CLOSE:
            SDL_HideWindow(mWindow);
            break;
    }
}

void IWindow::focus()
{
    // Show window if not shown
	if (!shown)
	{
		SDL_ShowWindow(window);
	}

	// Move window forward
	SDL_RaiseWindow(window);
}

bool IWindow::HasFocus()
{
    return mouseFocus;
}

bool IWindow::hasKeyboardFocus()
{
    return hasKeyboardFocus;
}

bool IWindow::isShown()
{
    return shown;
}

Vec2 IWindow::ToScreenCoordinate(Vec2 window_pos)
{

}

Vec2 IWindow::ToWindowCoordinate(Vec2 screen_pos)
{
    
}