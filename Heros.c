#include "prototypes.h"

//on creer notre Heros
Heros* create_heros(float proj_speed, int attack_speed )
{
    Heros* h=malloc(sizeof(Heros));
    h->heros_attack = BASE_HEROS_DAMAGE;
    h->base_heros_attack = BASE_HEROS_DAMAGE;
    h->projectile_speed = proj_speed;
    return h;
}

//On detruit notre heros
void destroy_heros(Heros* h)
{
    free(h);
    h=NULL;
}

//Fonction qui permet d'up notre heros
void upgrade_heros_damage(Heros h)
{
    h.heros_attack = h.heros_attack + COEFF_HEROS_UPGRADE_DAMAGE ;
    return;
}

//Fonction qui permet de reduire le temps entre deux tirs.
void upgrade_heros_attack_speed(Heros h)
{
    h.heros_attack_speed = h.heros_attack_speed + COEFF_HEROS_UPGRADE_ATTACK_SPEED ;
    return;
}
