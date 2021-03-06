
#ifndef DEF_STRUCTS
#define DEF_STRUCTS

#include "defs.h"

// Structure pour g�rer l'input clavier et souris

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
    //On defini ce qu'il sera utiliser comme �l�ment visuel dans map
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
    SDL_Texture* texture;
    SDL_Surface* image;
    int animX;
    int animY;
    int animTime;
    int x,y,w,t;
    bool is_shooting;
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
    SDL_Texture* texture;
    SDL_Surface* image;
    int animX;
    bool is_boss;
    Vector_2D ennemi_dimention;
    int animTime;
    int x,y,w,t;
    int animY;
}Ennemi;

typedef struct Building
{
    int base_building_life;
    int building_life ;
    Vector_2D building_pos;
}Building;

typedef struct Projectile
{
    int projectile_damages;
    float projectile_speed;
    Vector_2D projectile_direction;
    Vector_2D projectile_pos;
    SDL_Texture* texture;
    SDL_Surface* image;
    int x,y,w,t;

}Projectile;


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
