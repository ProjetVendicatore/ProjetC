#include "prototypes.h"

Weapon* create_Weapon(int attack, int attack_speed,int speed)
{
    Weapon* w=malloc(size(Weapon));
    w->weapon_attack=attack;
    w->weapon_attack_speed=attack_speed;
    w->weapon_speed=speed;

}

Weapon* Upgrade_weapon(Weapon w)
{
    if (coins >= COST )
    {
    w.weapon_attack = w.weapon_attack + COEFF_WEAPON_UPGRADE ;
    //Faire un truc qui affiche "Upgrade purchase"
    return w;
    }
    else
}


