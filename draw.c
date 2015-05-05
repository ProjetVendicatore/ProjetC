#include "prototypes.h"


void drawGame(void)
{
    // Remplis le renderer de noir, efface l'�cran et l'affiche.

    SDL_SetRenderDrawColor(getrenderer(), 0, 0, 0, 255);
    SDL_RenderClear(getrenderer());
    SDL_RenderPresent(getrenderer());

    // D�lai pour laisser respirer le proc
    SDL_Delay(1);
}

void delay(unsigned int frameLimit)
{
    // Gestion des 60 fps (images/stories/seconde)
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}
