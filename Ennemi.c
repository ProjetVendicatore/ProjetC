#include "prototypes.h"

//On creer un ennemi
Ennemi* create_ennemi(Vector_2D pos,int type)
{
    Ennemi* e=malloc(sizeof(Ennemi));
    e->ennemi_type=type;
    e->ennemi_position=pos;
    e->is_moving=true;
    e->animX=0;
    //On différencie 4 types d'ennemi , avec des stats différentes.
    if(type == 1) {
        e->is_boss = false;
        e->speed = BASE_ENNEMI_SPEED_TYPE1;
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE1;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE1;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE1;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE1;

        e->image = SDL_LoadBMP("graphics/ennemi_type1.png");
        SDL_SetColorKey( e->image, SDL_TRUE, SDL_MapRGB(e->image->format, 255, 0, 255));
        e->texture = SDL_CreateTextureFromSurface(renderer, e->image);

        return e;

     } else if ( type == 2)
     {  e->is_boss = false;
        e->speed = BASE_ENNEMI_SPEED_TYPE2;
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE2;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE2;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE2;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE2;

        e->image = SDL_LoadBMP("graphics/ennemi_type2.png");
        SDL_SetColorKey( e->image, SDL_TRUE, SDL_MapRGB(e->image->format, 255, 0, 255));
        e->texture = SDL_CreateTextureFromSurface(renderer, e->image);

        return e;

     } else if ( type == 3)
     {  e->is_boss = false;
        e->speed = BASE_ENNEMI_SPEED_TYPE3;
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE3;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE3;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE3;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE3;

        e->image = SDL_LoadBMP("graphics/ennemi_type3.png");
        SDL_SetColorKey( e->image, SDL_TRUE, SDL_MapRGB(e->image->format, 255, 0, 255));
        e->texture = SDL_CreateTextureFromSurface(renderer, e->image);

        return e;

     } else
     {  e->is_boss = true ;
        e->speed = BASE_ENNEMI_SPEED_TYPE3;
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE3;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE3;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE3;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE3;

        e->image = SDL_LoadBMP("graphics/Boss.png");
        SDL_SetColorKey( e->image, SDL_TRUE, SDL_MapRGB(e->image->format, 255, 0, 255));
        e->texture = SDL_CreateTextureFromSurface(renderer, e->image);

        return e;
     }
}

//on detruit un ennemi
void destroy_ennemi(Ennemi* e)
{
    SDL_DestroyTexture(e->texture);
    free(e);
    e=NULL;
}

//On actualise la position de l'ennemi ( fonction qui le fait bouger )
void update_Ennemi(Ennemi* ennemi, float timeDelta)
{
    if(ennemi != NULL)
    {
        if(ennemi->is_moving == true)
        {
            ennemi->ennemi_position.x -= ennemi->speed* timeDelta;
            if(ennemi->ennemi_position.x  >= LIMIT_ENNEMI_X)
            {
                ennemi->ennemi_position.x= LIMIT_ENNEMI_X;
                ennemi->is_moving = false;
            }
        }
    }
}

