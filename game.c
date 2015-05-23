#include "prototypes.h"
/* A mettre dans main.c
void Init()
{
HP = 50;
srand(time(NULL));

spawnTimer = 0.0f;

ennemiList = lList_create();
bulletList = lList_create();

lList_Show(ennemiList, "ennemi");
UpdateHPText();
}
*/
spawnTimer = 0.0f ;

void GameLoop(float timeDelta)
{
spawnTimer += timeDelta;
if(spawnTimer > 2.0f)
{
spawnTimer -= 2.0f;
int line = rand() % 6;
int type = rand() % 2;
Ennemi* newEnnemi = Ennemi_create((0, line * 80 + 40  ) , type+1);
lList_append(ennemiList, newEnnemi);
// Rajouter l'ennemi
lList_Show(ennemiList, "ennemi");
// Faire apparaitre la liste (facultatif)
}

if(ennemiList != NULL)
{
lNode* ennemiNode = ennemiList->p_head;
// R�cup�rer la t�te
while(ennemiNode)
{
Ennemi* ennemi = (Ennemi*)ennemiNode->p_elem;
Ennemi_Update(ennemi, _timeDelta);
ennemiNode = ennemiNode->p_next;
}
}

if(bulletList != NULL)
{
lNode* bulletNode = bulletList->p_head;
while(bulletNode)
{
Projectile* projectile = (Projectile*)bulletNode->p_elem;
Projectile_Update(projectile, timeDelta);
bulletNode = bulletNode->p_next;
}
}
CheckForCollisions();
// Parcours tous les ennemis et tous les projectiles si �a match retirer des points de vie
//si les points de vie sont � 0 retirer l'ennemi de la liste
// De m�me avec les projectiles, ils disparaissent lors d'une collision et lorsqu'ils sortent de l'�cran
// A faire
}


