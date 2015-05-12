#include"prototypes.h"

Projectile* create_projectile(int damage,int speed,Position init_pos)
{
    Projectile* p=malloc(size(Projectile));
    p->projectile_damage=damage;
    p->projectile_speed=speed;
    p->init_proj_pos=init_pos;
    return p;
}

Position* calcul_trajectoire(Position pos_A ,Position pos_B)
{

}

void throw_projectile(Position pos_A,Position pos_B)
{
    p=create_projectile()

    if (calcul_trajectoire(h.pos_heros,p.next_proj_pos) == e.next_pos_ennemi)
    {
        e.ennemi_life = e.ennemi_life - p.projectile_damage

        if (e.ennemi_life <= 0)
        {
            destroy_ennemi(e);
        }
        else
        {
         destroy_projectile(p);
        }
    }
    if (p.projectile_time >= 4000)
    {
        destroy_projectile(p);
    }
     else
     {
         throw_projectile(p.next_projectile_pos,e.next_pos_ennemi);
     }
}

void destroy_projectile(Projectile p)
{
    free(p);
}
