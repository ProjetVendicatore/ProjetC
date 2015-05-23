#include"prototypes.h"

//On creer un projectile
Projectile* create_projectile(Vector_2D position,Vector_2D direct, float speed, int damage)
{
    Projectile* p=malloc(sizeof(Projectile));

    p->projectile_damage=damage;
    p->projectile_speed=speed;
    p->projectile_direction=direct;
    p->projectile_direction=vector_normalize(p->projectile_direction);
    p->projectile_pos=position;

    return p;
}

//On detruit un projectile
void destroy_projectile(Projectile* p)
{
    free(p);
    p=NULL;
}

void update_Projectile(Projectile* proj, float timeDelta)
{
    if(proj != NULL)
    {
        proj->projectile_pos = vector_addition(proj->projectile_pos, vector_multiply(proj->projectile_direction, proj->projectile_speed * timeDelta));
    }
}
