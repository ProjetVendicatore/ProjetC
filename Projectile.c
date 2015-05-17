#include"prototypes.h"

Projectile* create_projectile(int posY, int posX, float dirX, float dirY, float speed, int damage)
{
    Projectile* p=malloc(sizeof(Projectile));

    p->projectile_damage=damage;
    p->projectile_speed=speed;
    p->projectile_direction.x = dirX;
    p->projectile_direction.y = dirY;
    p->projectile_direction = vector_normalize(p->projectile_direction);
    p->projectile_pos.x = posX;
    p->projectile_pos.y = posY;

    return p;
}


void destroy_projectile(Projectile* p)
{
    free(p);
    p=NULL;
}

void update_proj(Projectile* proj, float timeDelta)
{
    if( proj != NULL)
    {
        proj->projectile_pos = vector_addition(proj->projectile_pos, vector_multiply(proj->projectile_direction, proj->projectile_speed * timeDelta));
    }
}
