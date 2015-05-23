#include "prototypes.h"

//on creer notre Heros
Heros* create_heros()
{
    Heros* h=malloc(sizeof(Heros));
    h->heros_attack = BASE_HEROS_DAMAGE;
    h->base_heros_attack = BASE_HEROS_DAMAGE;
    h->image = SDL_LoadBMP("graphics/heros.png");
    SDL_SetColorKey( h->image, SDL_TRUE, SDL_MapRGB(h->image->format, 255, 0, 255));
    h->texture = SDL_CreateTextureFromSurface(renderer, h->image);
    h->animX=0;
    return h;
}

//On detruit notre heros
void destroy_heros(Heros* h)
{
    SDL_DestroyTexture(f->texture);
    free(h);
    h=NULL;
}

//Fonction qui permet d'up notre heros
void upgrade_heros_damage(Heros* h)
{
    h->heros_attack = h.heros_attack + COEFF_HEROS_UPGRADE_DAMAGE ;
    return;
}
