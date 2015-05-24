#include "prototypes.h"
lList* ennemiList ;
lList* bulletList ;
SDL_Renderer* renderer;


void CheckForCollisions()
{
    if(ennemiList != NULL && bulletList != NULL)
    {
        lNode* ennemiNode = ennemiList->p_head;
        while(ennemiNode)
        {
            Ennemi* ennemi = (Ennemi*)ennemiNode->p_elem;
            ennemiNode = ennemiNode->p_next;
            if(ennemi != NULL)
            {
                lNode* bulletNode = bulletList->p_head;
                while(bulletNode)
                {
                    Projectile* projectile = (Projectile*)bulletNode->p_elem;

                    bulletNode = bulletNode->p_next;
                    if(projectile != NULL)
                    {
                        if(is_inside_rect(projectile->projectile_pos.x, projectile->projectile_pos.y, ennemi->ennemi_position.x, ennemi->ennemi_position.y, ennemi->ennemi_dimention.x, ennemi->ennemi_dimention.y))
                        {
                            ennemi->ennemi_life -= projectile->projectile_damages;
                            lList_remove(bulletList, projectile);
                            free(projectile);
                            lList_Show(bulletList, "bullet");

                            if(ennemi->ennemi_life <= 0)
                            {
                                bulletNode = NULL;
                            }
                        }
                    }
                }
                if(ennemi->ennemi_life <= 0)
                {
                    lList_remove(ennemiList, ennemi);
                    free(ennemi);
                    lList_Show(ennemiList, "ennemi");
                }
            }
        }
    }
    lNode* bulletNode = bulletList->p_head;
    while(bulletNode)
    {
        Projectile* projectile = (Projectile*)bulletNode->p_elem;
        if(projectile != NULL)
        {
            if(projectile->projectile_pos.x < 0 || projectile->projectile_pos.x > 640 || projectile->projectile_pos.y < 0 || projectile->projectile_pos.y > 480)
            {
                bulletNode = bulletNode->p_next;

                lList_remove(bulletList, projectile);
                free(projectile);
                lList_Show(bulletList, "bullet");
            }
            else
            {
                bulletNode = bulletNode->p_next;
            }
        }
    }
}
spawnTimer = 0.0f ;

void GameLoop(float timeDelta)
{
spawnTimer += timeDelta;
if(spawnTimer > 2.0f)
{
spawnTimer -= 2.0f;
float line = rand() % 6;
int type = rand() % 2;
Ennemi* newEnnemi = create_ennemi(line * 80 + 40 , type+1,renderer);
lList_append(ennemiList, newEnnemi);
// Rajouter l'ennemi
lList_Show(ennemiList, "ennemi");
// Faire apparaitre la liste (facultatif)
}

if(ennemiList != NULL)
{
lNode* ennemiNode = ennemiList->p_head;
// Récupérer la tete
while(ennemiNode)
{
Ennemi* ennemi = (Ennemi*)ennemiNode->p_elem;
update_Ennemi(ennemi, timeDelta);
ennemiNode = ennemiNode->p_next;
}
}

if(bulletList != NULL)
{
lNode* bulletNode = bulletList->p_head;
while(bulletNode)
{
Projectile* projectile = (Projectile*)bulletNode->p_elem;
update_Projectile(projectile, timeDelta);
bulletNode = bulletNode->p_next;
}
}

CheckForCollisions();
// Parcours tout les ennemis et tout les projectile si ca match retirer des points de vie
//si les points de vie sont a 0 retirer l'ennemi de la liste
// De meme avec les projectiles ils disparaissent lors d'une collision et lorsqu'ils sortent de l'écranv
// A faire
}


