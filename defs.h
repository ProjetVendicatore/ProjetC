//On met tout les includes ici , et il suffit juste d'inclure ce .h dans les autres.
#ifndef DEF_DEFS
#define DEF_DEFS

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

// Taille de la fenêtre et des titles et boucle d'animation
#define ANIM_SPEED 6 // vitesse d'animation des sprites

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480

#define HEROS_T_HEIGHT 60
#define HEROS_T_WEIGHT 50
#define HEROS_SHOOTING_T_HEIGHT 80
#define HEROS_SHOOTING_T_WEIGHT 70
#define HEROS_ANIM_SHOOTING_LIMIT 8
#define HEROS_ANIM_LIMIT 7


#define PROJ_T_HEIGHT 80
#define PROJ_T_WEIGHT 60

#define ENNEMI_T_HEIGHT 60
#define ENNEMI_T_WEIGHT 60
#define ENNEMI_BOSS_T_HEIGHT 80
#define ENNEMI_BOSS_T_WEIGHT 80
#define ENNEMI_ANIM_LIMIT_TYPE1 7
#define ENNEMI_ANIM_LIMIT_TYPE2 7
#define ENNEMI_ANIM_LIMIT_TYPE3 9
#define ENNEMI_ANIM_LIMIT_BOSS 9


//On va ajouter toutes les autres constantes
#define BASE_LIFE_BUILDING 5000
#define COEFF_BUILDING_UPGRADE 100
#define COST_BUILDING_UPGRADE 200
#define INIT_POS_X_BUILDING 300.0
#define INIT_POS_Y_BUILDING 300.0

//Ennemi
#define BASE_ENNEMI_DAMAGE_TYPE1 50
#define BASE_ENNEMI_DAMAGE_TYPE2 50
#define BASE_ENNEMI_DAMAGE_TYPE3 50
#define BASE_ENNEMI_DAMAGE_TYPE4 50

#define BASE_ENNEMI_HEALTH_TYPE1 50
#define BASE_ENNEMI_HEALTH_TYPE2 50
#define BASE_ENNEMI_HEALTH_TYPE3 50
#define BASE_ENNEMI_HEALTH_TYPE4 50

#define BASE_ENNEMI_SPEED_TYPE1 30
#define BASE_ENNEMI_SPEED_TYPE2 30
#define BASE_ENNEMI_SPEED_TYPE3 30
#define BASE_ENNEMI_SPEED_TYPE4 30

#define LIMIT_ENNEMI_X 100
#define STARTING_ENNEMI_X 800

//Heros
#define BASE_HEROS_DAMAGE 20
#define COEFF_HEROS_UPGRADE_DAMAGE 50
#define COEFF_HEROS_UPGRADE_ATTACK_SPEED 50
#define COST_HEROS_UPGRADE_ATTACK 200
#define COST_HEROS_UPGRADE_ATTACK_SPEED 200

#define INIT_POS_X_HEROS 100
#define INIT_POS_Y_HEROS 100




#endif
