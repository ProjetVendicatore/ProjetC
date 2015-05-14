#include "prototypes.h"

Heros* create_heros(int attack, Weapon weapon )
{
    Heros* h=malloc(sizeof(Heros));
    h->heros_attack = attack;
    h->heros_weapon = weapon;
    return h;
}

void destroy_heros(Heros h)
{
    free(h);
}


