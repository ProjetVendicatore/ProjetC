#include"prototypes.h"

//On va creer un projectile

Projectile* create_projectile(int posX, int posY, float dirX, float dirY, float speed, int damages,SDL_Renderer* renderer)
{
    Projectile* newProjectile = malloc(sizeof(Projectile));
    newProjectile->position.x = posX;
    newProjectile->position.y = posY;
    newProjectile->direction.x = dirX;
    newProjectile->direction.y = dirY;
    newProjectile->direction = vector_normalize(newProjectile->direction);
    newProjectile->speed = speed;
    newProjectile->damage = damages;
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
        proj->position = vector_addition(proj->position, vector_multiply(proj->direction, proj->speed * timeDelta));

    }
}
