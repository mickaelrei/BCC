#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>

class RGB
{
public:
	unsigned char R;
	unsigned char G;
	unsigned char B;

	RGB(unsigned char r, unsigned char g, unsigned char b)
	{
		R = r;
		G = g;
		B = b;
	}

	bool Equals(RGB rgb)
	{
		return (R == rgb.R) && (G == rgb.G) && (B == rgb.B);
	}
};

class HSL
{
public:
	int H;
	float S;
	float L;

	HSL(int h, float s, float l)
	{
		H = h;
		S = s;
		L = l;
	}

	bool Equals(HSL hsl)
	{
		return (H == hsl.H) && (S == hsl.S) && (L == hsl.L);
	}
};

static float HueToRGB(float v1, float v2, float vH) {
	if (vH < 0)
		vH += 1;

	if (vH > 1)
		vH -= 1;

	if ((6 * vH) < 1)
		return (v1 + (v2 - v1) * 6 * vH);

	if ((2 * vH) < 1)
		return v2;

	if ((3 * vH) < 2)
		return (v1 + (v2 - v1) * ((2.0f / 3) - vH) * 6);

	return v1;
}

static RGB HSLToRGB(HSL hsl) {
	unsigned char r = 0;
	unsigned char g = 0;
	unsigned char b = 0;

	if (hsl.S == 0)
	{
		r = g = b = (unsigned char)(hsl.L * 255);
	}
	else
	{
		float v1, v2;
		float hue = (float)hsl.H / 360;

		v2 = (hsl.L < 0.5) ? (hsl.L * (1 + hsl.S)) : ((hsl.L + hsl.S) - (hsl.L * hsl.S));
		v1 = 2 * hsl.L - v2;

		r = (unsigned char)(255 * HueToRGB(v1, v2, hue + (1.0f / 3)));
		g = (unsigned char)(255 * HueToRGB(v1, v2, hue));
		b = (unsigned char)(255 * HueToRGB(v1, v2, hue - (1.0f / 3)));
	}

	return RGB(r, g, b);
}

SDL_Window *window;
SDL_Surface *windowSurface;
SDL_Renderer *renderer;
const int width = 600, height = 600;

bool init() {
    if (! SDL_Init( SDL_INIT_VIDEO ) < 0) {
        std::cout << "Error initializing video: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(
        "Drawing circle",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        0
    );

    if (!window) {
        std::cout << "Error creating window: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
        return false;
    }

    windowSurface = SDL_GetWindowSurface(window);
    if (!windowSurface) {
        std::cout << "Error getting window surface: " << SDL_GetError() << std::endl;
        return false;
    }

    // SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0xFF, 0xFF, 0xFF));
    // SDL_UpdateWindowSurface(window);

    return true;
}

RGB getColorFromAngle(float angle)
{
    int hue = (int)(angle/2 * 360) % 360;
    HSL colorHSL = HSL(hue, 1.0f, .5f);

    return HSLToRGB(colorHSL);
}

void drawCircle(int centerX, int centerY, int radius, int width = 1)
{
    for (float angle = 0; angle < 2 * M_PI; angle += M_PI / (360 * radius / 50))
    {
        if (width > 1)
        {
            for (int r = -width / 2; r <= width / 2; r++)
            {
                int newRadius = radius + r;
                int x = centerX + cos(angle) * newRadius;
                int y = centerY + sin(angle) * newRadius;

                // Get color from angle
                RGB c = getColorFromAngle(angle);

                // SDL_SetRenderDrawColor(renderer, c.R, c.G, c.B, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        } else
        {
            int x = centerX + cos(angle) * radius;
            int y = centerY + sin(angle) * radius;

            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

int main(int argc, char **argv)
{
    if (!init())
    {
        return -1;
    }

    int mouseX, mouseY;
    int radius = 50;
    int min_radius = 3, max_radius = width/2;
    int scroll_diff = 4;

    // Loop
    SDL_Event e;
    bool running = true;
    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            running = false;
                            break;
                    }
                    break;
                case SDL_MOUSEWHEEL:
                    // std::cout << "whell scroll: (" << e.wheel.x << ", " << e.wheel.y << ")\n";
                    radius = SDL_clamp(radius + scroll_diff * e.wheel.y, min_radius, max_radius);
                    break;
                default:
                    break;
            }
        }

        SDL_GetMouseState(&mouseX, &mouseY);

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        drawCircle(mouseX, mouseY, radius, 50);

        SDL_RenderPresent(renderer);
    }
}