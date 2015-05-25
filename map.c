#include"prototypes.h"

Map map;
//On defini le background de la map
void initMaps()
{
    map.background=loadImage("bin/graphics/Background.png");
}

//Fonction pour accerder au background
SDL_Texture *getBackground()
{
    return map.background;
}

//On nettoye la map
void cleanMaps()
{
    if (map.background != NULL)
    {
        SDL_DestroyTexture(map.background);
        map.background = NULL;
    }
}
