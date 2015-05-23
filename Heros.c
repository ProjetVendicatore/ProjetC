#include "prototypes.h"


//on creer notre Heros
Heros* create_heros()
{
    Heros* h=malloc(sizeof(Heros));
    h->heros_attack = BASE_HEROS_DAMAGE;
    h->base_heros_attack = BASE_HEROS_DAMAGE;
    return h;
}

//On detruit notre heros
void destroy_heros(Heros* h)
{
    free(h);
    h=NULL;
}

//Fonction qui permet d'up notre heros
void upgrade_heros_damage(Heros* h)
{
    h->heros_attack = h->heros_attack + 2 ;
    return;
}
