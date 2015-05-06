#include"prototypes.h"

Map map;

void initMaps()
{
    map.background=loadImage("graphics/Background.png");
}

SDL_Texture *getBackground()
{
    return map.background;
}

void cleanMaps()
{
    if (map.background != NULL)
    {
        SDL_DestroyTexture(map.background);
        map.background = NULL;
    }
}
