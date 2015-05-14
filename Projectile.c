#include"prototypes.h"

Projectile* create_projectile(int damage,int speed)
{
    Projectile* p=malloc(sizeof(Projectile));
    //mettre les getter de pos

    p->projectile_damage=damage;
    p->projectile_speed=speed;
}
