
#ifndef DEF_STRUCTS
#define DEF_STRUCTS

#include "defs.h"

// Structure pour gérer l'input clavier et souris

typedef struct Input
{
    int pause,firstspell,secondspell,thirdspell,leftclik,rightclik;
}Input;

typedef struct Map
{
    //On defini ce qu'il sera utiliser comme élément visuel dans map
    SDL_Texture *background;
}Map;

typedef struct Vector_2D
{
    float x;
    float y;
}Vector_2D;

typedef struct Heros
{   int base_heros_attack;
    int heros_attack ;
    int heros_attack_speed;
    float projectile_speed;
}Heros;

typedef struct Ennemi
{
    int base_ennemi_attack;
    int ennemi_attack;
    int base_ennemi_life;
    int ennemi_life;
    int ennemi_type;
    Vector_2D init_ennemi_position;
}Ennemi;

typedef struct Building
{
    int base_building_life;
    int *building_life ;
    Vector_2D building_pos;
}Building;

typedef struct Projectile
{
    int projectile_damage;
    float projectile_speed;
    Vector_2D projectile_direction;
    Vector_2D projectile_pos;

}Projectile;



#endif
