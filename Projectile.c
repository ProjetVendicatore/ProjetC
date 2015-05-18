#include"prototypes.h"

Projectile* create_projectile(Vector_2D position,Vector_2D direction, float speed, int damage)
{
    Projectile* p=malloc(sizeof(Projectile));

    p->projectile_damage=damage;
    p->projectile_speed=speed;
    p->projectile_direction=direction;
    p->projectile_pos=position;

    return p;
}

void destroy_projectile(Projectile* p)
{
    free(p);
    p=NULL;
}
