#include"prototypes.h"

Ennemi* create_ennemi(int attack,Position init_pos ,char* type)
{
    Ennemi* e=malloc(size(Ennemi));
    e->ennemi_attack=attack;
    e->init_ennemi_pos=init_pos;
    e->ennemi_type=type;
    return e;
}

void destroy_ennemi(Ennemi e)
{
    free(e);
}

void move_ennemi(Ennemi e, Position pos_B)
{

}
