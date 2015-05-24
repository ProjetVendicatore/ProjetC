#include "prototypes.h"

/* Déclaration des variables / structures utilisées par le jeu */
Input input;
SDL_Window* window;
SDL_Renderer* renderer;
bool running = true;
lList* ennemiList;
lList* bulletList;
//float spawnTimer;
Vector_2D mousePosition;
TTF_Font* police;
SDL_Surface* HPText;
SDL_Rect HPTextPosition;
int HP;



void HandleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            running = false;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            SDL_Keycode key = event.key.keysym.sym;
            if(key == SDLK_ESCAPE)
            {
                running = false;
            }
        }
        else if (event.type == SDL_MOUSEMOTION)
        {
            mousePosition.x = event.motion.x;
            mousePosition.y = event.motion.y;
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button == 1)
            {
                Projectile* newBullet = create_projectile(580, 480/2, event.motion.x - 580, event.motion.y - 480/2, 300.0f, 5,renderer );
                lList_append(bulletList, newBullet);

                lList_Show(bulletList, "bullet");
            }
        }
    }
}

int main(int argc, char *argv[])
{
    TTF_Init();
    police = TTF_OpenFont("verdana.ttf", 12);
    if (SDL_INIT_EVERYTHING<0)
    {
        return -1 ;
    }
    window = SDL_CreateWindow("Un jeu beaucoup trop stylééé", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        return -2;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        printf(SDL_GetError());
        return -3;
    }
    Uint32 old_time, current_time;
    float timeDelta;

    current_time = SDL_GetTicks();
    while (running)
    {
    HandleEvents();
    Init();
    GameLoop(timeDelta);
    Render();
    destroy_lList(ennemiList);
    ennemiList = NULL;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_CloseFont(police);
    TTF_Quit();


    }
      // On quitte
    return(0);
}
