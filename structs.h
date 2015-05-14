
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

typedef struct Weapon
{
    int base_weapon_attack;
    int base_weapon_attack_speed;
    int weapon_attack;
    int weapon_attack_speed;
    int weapon_speed;
}Weapon;

typedef struct Heros
{   int base_heros_attack;
    int *heros_attack ;
    Weapon *heros_weapon ;
    Position init_heros_position;
}Heros;

typedef struct Ennemi
{
    int base_ennemi_attack;
    int ennemi_attack;
    int base_ennemi_life;
    int ennemi_life;
    Position init_ennemi_pos ;
    Position next_ennemi_position;
    char* ennemi_type;
}

typedef struct Building
{
    int base_building_life;
    int building_life ;
    int base_building
    int building_def ;
    Position init_building_pos;
}Building;

typedef struct Projectile
{
    int projectile_damage;
    int projectile_direction;
    int projectile_speed;
    int projectile_time;
    Position init_proj_pos,next_proj_pos;

}Projectile;

typedef struct Position
{
    int x ,y;
}Position;

#endif
