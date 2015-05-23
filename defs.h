//On met tous les includes ici , et il suffit juste d'inclure ce .h dans les autres.
#ifndef DEF_DEFS
#define DEF_DEFS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

// Taille de la fenêtre et des titles
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480
#define TITLES_HEIGHT 64
#define TITLES_WEIGHT 64

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

//Heros
#define BASE_HEROS_DAMAGE 20
#define COEFF_HEROS_UPGRADE_DAMAGE 50
#define COEFF_HEROS_UPGRADE_ATTACK_SPEED 50
#define COST_HEROS_UPGRADE_ATTACK 200
#define COST_HEROS_UPGRADE_ATTACK_SPEED 200

#endif
