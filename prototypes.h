#include "structs.h"

#ifndef PROTOTYPES
#define PROTOTYPES

// Catalogue des prototypes des fonctions utilisées.

//Init
extern SDL_Renderer *getrenderer(void);
extern void cleanup(void);
extern void loadGame();
extern void init(char *);


//Input
extern void gestionInputs(Input *input);
extern void getInput(Input *input);


//Draw
extern void delay(unsigned int frameLimit);
extern void drawGame(void);
extern SDL_Texture *loadImage(char *name);
extern void drawImage(SDL_Texture *image, int x, int y);

//Map
extern void initMaps();
extern SDL_Texture *getBackground();
extern void cleanMaps();

//Ennemi
extern Ennemi* create_ennemi(Vector_2D pos,int type);
extern void destroy_ennemi(Ennemi* e);


//Heros
extern Heros* create_heros(float proj_speed, int attack_speed );
extern void destroy_heros(Heros* h);
extern void upgrade_heros_damage(Heros h);
extern void upgrade_heros_attack_speed(Heros h);


//Building
extern Building* create_building(Vector_2D vect);
extern void destroy_building(Building* b);


//Projectile
extern Projectile* create_projectile(Vector_2D position,Vector_2D direction, float speed, int damage);
extern void destroy_projectile(Projectile* p);


//Vector_2D
extern Vector_2D* create_vector(float x ,float y);
extern Vector_2D* vector_addition(Vector_2D vector1 , Vector_2D vector2);
extern Vector_2D* vector_subtraction(Vector_2D vector1 , Vector_2D vector2);
extern float vector_length(Vector_2D vector1);
extern Vector_2D* vector_normalize(Vector_2D vector1);
extern Vector_2D* vector_multiply(Vector_2D vector1,float coeff);

//Menu
extern void menu1(Input *input);
extern void menu2(Input *input);
extern void menuHelp(Input *input);
extern void menuLose(Input *input);
extern void menuWin(Input *input);
extern void menuGame(Input *input);
extern void menuBreak(Input *input);
extern void Mouse();

//Read_level
extern int read_level(char* level_number);

#endif
