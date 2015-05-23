
#ifndef DEF_STRUCTS
#define DEF_STRUCTS

#include "defs.h"

// Structure pour gérer l'input clavier et souris

typedef struct Input
{
    int pause;
    int firstspell;
    int secondspell;
    int thirdspell;
    int leftclik ;
    int rightclik;
}Input;

typedef struct Map
{
    //On defini ce qu'il sera utiliser comme élément visuel dans map
    SDL_Texture *background;
}Map;

typedef struct Vector_2D Vector_2D ;
struct Vector_2D
{
    float x;
    float y;
};

typedef struct Heros
{   int base_heros_attack;
    int heros_attack ;
}Heros;

typedef struct Ennemi
{
    int base_ennemi_attack;
    int ennemi_attack;
    int base_ennemi_life;
    int ennemi_life;
    int ennemi_type;
    Vector_2D ennemi_position;
    bool is_moving;
    float speed;
}Ennemi;

typedef struct Building
{
    int base_building_life;
    int building_life ;
    Vector_2D building_pos;
}Building;

typedef struct Projectile Projectile;

struct Projectile
{
    int damage;
    float speed;
    Vector_2D direction;
    Vector_2D position;
};


typedef struct lNode lNode;

struct lNode
{
    void* p_elem;
    lNode* p_next;
};

typedef struct lList
{
int elemCount;
lNode* p_head;
lNode* p_tail;
}lList;


#endif
