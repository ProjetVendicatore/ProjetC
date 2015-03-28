
#include <stdbool.h>
#include "sdl.h"
/*#include "character.h"
#include "ennemi.h"*/

SDL_Window* window;
SDL_Renderer* renderer;
bool running;

void GameLoop(float _timeDelta)
{
    printf("delta time = %f", _timeDelta);
}

void HandleEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
        {
            running = false;
        }
        if(event.type == SDL_KEYDOWN)
        {
            SDL_Keycode key = event.key.keysym.sym;
            if(key == SDLK_ESCAPE)
            {
                running = false;
            }
        }
    }
}

void Render()
{
    //Get window surface
    SDL_Surface* screenSurface = SDL_GetWindowSurface( window );

    //Fill the surface white
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );


    //Update the surface
    SDL_UpdateWindowSurface( window );
}

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return -1;
    }
    window = SDL_CreateWindow("My game", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        return -2;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        return -3;
    }
    running = true;
    Uint32 old_time, current_time;
    float timeDelta;

    current_time = SDL_GetTicks();
    while (running)
    {
        // Update the timing information
        old_time = current_time;

        current_time = SDL_GetTicks();
        timeDelta = (current_time - old_time) / 1000.0f;


        HandleEvent();
        GameLoop(timeDelta);
        Render();
        printf("%f\n", timeDelta);
        Uint32 frameTime = SDL_GetTicks() - current_time;
        if(frameTime < 16)
        {
            SDL_Delay( 16 - frameTime);
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
