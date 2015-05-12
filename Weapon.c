#include "prototypes.h"

Weapon* create_Weapon(int attack, int attack_speed,int speed)
{
    Weapon* w=malloc(size(Weapon));
    w->weapon_attack=attack;
    w->weapon_attack_speed=attack_speed;
    w->weapon_speed=speed;

}


