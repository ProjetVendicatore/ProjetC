
#ifndef DEF_STRUCTS
#define DEF_STRUCTS

#include "defs.h"

// Structure pour gérer l'input clavier et souris

typedef struct Input
{
    int pause,firstspell,secondspell,thirdspell,leftclik,rightclik;
}
Input;

typedef struct Map
{
    //On defini ce qu'il sera utiliser comme élément visuel dans map
    SDL_Texture *background;
}
Map;

typedef struct Weapon
{
 int attack,attack_speed
}
Weapon;

typedef struct Heros
{
    int *heros_attack ;
    Weapon *heros_weapon ;
}Heros;

typedef struct Building
{
    int building_life ;
    int building_def ;
}
#endif
