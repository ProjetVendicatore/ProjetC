#include "prototypes.h"

Heros* create_heros(float proj_speed, int attack_speed )
{
    Heros* h=malloc(sizeof(Heros));
    h->heros_attack = BASE_HEROS_DAMAGE;
    h->base_heros_attack = BASE_HEROS_DAMAGE;
    h->projectile_speed = proj_speed;
    return h;
}

void destroy_heros(Heros* h)
{
    free(h);
    h=NULL;
}

void upgrade_heros_damage(Heros h)
{
    h.heros_attack = h.heros_attack + COEFF_HEROS_UPGRADE_DAMAGE ;
    return;
}

void upgrade_heros_attack_speed(Heros h)
{
    h.heros_attack_speed = h.heros_attack_speed + COEFF_HEROS_UPGRADE_ATTACK_SPEED ;
    return;
}
