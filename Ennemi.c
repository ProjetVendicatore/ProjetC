#include"prototypes.h"

Ennemi* create_ennemi(int posY,int type)
{
    Ennemi* e = malloc(sizeof(Ennemi));
    e->ennemi_type=type;
    e->init_ennemi_position.x=INIT_ENNEMI_POS_X;
    e->init_ennemi_position.y=posY;
    e->ennemi_moving = true;
    if(type == 1) {
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE1;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE1;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE1;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE1;
        return e;
     } else if ( type == 2)
     {
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE2;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE2;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE2;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE2;
        return e;
     } else if ( type ==3 )
     {
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE3;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE3;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE3;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE3;
        return e;
     } else
     {
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE4;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE4;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE4;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE4;
        return e;
     }
}

void destroy_ennemi(Ennemi* e)
{
    free(e);
    e=NULL;
}

// void move_ennemi(Ennemi e, Position pos_B)
