
#include "prototypes.h"
#include "defs.h"

SDL_Window *screen;
SDL_Renderer *renderer;
lList* ennemiList ;
lList* bulletList ;
void Init()
{

srand(time(NULL));

float spawnTimer = 0.0f;

ennemiList = lList_create();
bulletList = lList_create();

lList_Show(ennemiList, "ennemi");
UpdateHPText();
}

