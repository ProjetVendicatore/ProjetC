#include"prototypes.h"

//On va creer un projectile

Projectile* create_projectile(int posX, int posY, float dirX, float dirY, float speed, int damages,SDL_Renderer* renderer)
{
    Projectile* newProjectile = malloc(sizeof(Projectile));
    newProjectile->projectile_pos.x = posX;
    newProjectile->projectile_pos.y = posY;
    newProjectile->projectile_direction.x = dirX;
    newProjectile->projectile_direction.y = dirY;
    newProjectile->projectile_direction = vector_normalize(newProjectile->projectile_direction);
    newProjectile->projectile_speed = speed;
    newProjectile->projectile_damages = damages;
    newProjectile->image = SDL_LoadBMP("graphics/proj.png");
    SDL_SetColorKey( newProjectile->image, SDL_TRUE, SDL_MapRGB(newProjectile->image->format, 255, 0, 255));
    newProjectile->texture = SDL_CreateTextureFromSurface(renderer, newProjectile->image);
    return newProjectile;
}
//On detruit un projectile
void destroy_projectile(Projectile* p)
{
    SDL_DestroyTexture(p->texture);
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
