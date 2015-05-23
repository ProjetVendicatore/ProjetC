#include "prototypes.h"

//On creer un ennemi
Ennemi* create_ennemi(Vector_2D pos,int type)
{
    Ennemi* e=malloc(sizeof(Ennemi));
    e->ennemi_type=type;
    e->ennemi_position=pos;
    e->is_moving=true;
    //On différencie 3 types d'ennemi , avec des stats différentes.
    if(type == 1) {
        e->speed = BASE_ENNEMI_SPEED_TYPE1;
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE1;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE1;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE1;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE1;
        return e;
     } else if ( type == 2)
     {
        e->speed = BASE_ENNEMI_SPEED_TYPE2;
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE2;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE2;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE2;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE2;
        return e;
     } else
     {
        e->speed = BASE_ENNEMI_SPEED_TYPE3;
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE3;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE3;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE3;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE3;
        return e;
     }
}

//on detruit un ennemi
void destroy_ennemi(Ennemi* e)
{
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

