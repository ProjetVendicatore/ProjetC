#include "prototypes.h"

SDL_Renderer* renderer;

void drawGame(void)
{

// Affiche le fond (background) aux coordonnées (0,0)
drawImage(getBackground(), 0, 0);

// Affiche l'écran
SDL_RenderPresent(renderer);

// Délai pour laisser respirer le proc
SDL_Delay(1);

}


SDL_Texture *loadImage(char *name)
{

/* Charge les images avec SDL Image dans une SDL_Surface */

SDL_Surface *loadedImage = NULL;
SDL_Texture *texture = NULL;
loadedImage = IMG_Load(name);

if (loadedImage != NULL)
{
// Conversion de l'image en texture
texture = SDL_CreateTextureFromSurface(renderer, loadedImage);

// On se débarrasse du pointeur vers une surface
SDL_FreeSurface(loadedImage);
loadedImage = NULL;
}
else
printf("L'image n'a pas pu être chargée! SDL_Error : %s\n", SDL_GetError());

return texture;

}


void drawImage(SDL_Texture *image, int x, int y)
{

SDL_Rect dest;

/* Règle le rectangle à dessiner selon la taille de l'image source */
dest.x = x;
dest.y = y;

/* Dessine l'image entière sur l'écran aux coordonnées x et y */
SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);
SDL_RenderCopy(renderer, image, NULL, &dest);

}
void delay(unsigned int frameLimit)
{
    // Gestion des 60 fps (images/stories/seconde)
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}
void drawHeros(SDL_Renderer *renderer, Heros* heros)
{
    //sert a enlever la couleur de fond
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    //drawRect(renderer, (int)heros->x, (int)heros->y, (int)heros->w, (int)heros->h);
    int wText, hText;
    //recuepre la taille de la texture
    SDL_QueryTexture(heros->texture, NULL, NULL, &wText, &hText);

    if(heros->is_shooting == true) {
    //On defini le rectangle qu'on veut creer dans l'image
    SDL_Rect source_rect = {heros->animX*HEROS_SHOOTING_T_WEIGHT, heros->animY*HEROS_SHOOTING_T_HEIGHT, HEROS_SHOOTING_T_WEIGHT, HEROS_SHOOTING_T_HEIGHT};
    //On choisi le rectangle qui se situe sur l'ecran
    SDL_Rect dest_rect = {(int)heros->x, (int)heros->y, (int)heros->w, (int)heros->t};
    SDL_Point center = {0, 0};
    //Ici flip permet d'inverser les sprites (horinzontal ou vertical , ici pas besoin , pas besoin d'angle non plus pour heros)
    SDL_RenderCopyEx(renderer, heros->texture, &source_rect, &dest_rect, 0, &center, SDL_FLIP_NONE);

    } else {
    //On defini le rectangle qu'on veut creer dans l'image
    SDL_Rect source_rect = {heros->animX*HEROS_T_WEIGHT, heros->animY*HEROS_T_HEIGHT, HEROS_T_WEIGHT, HEROS_T_HEIGHT};
    //On choisi le rectangle qui se situe sur l'ecran
    SDL_Rect dest_rect = {(int)heros->x, (int)heros->y, (int)heros->w, (int)heros->t};
    SDL_Point center = {0, 0};
    //Ici flip permet d'inverser les sprites (horinzontal ou vertical , ici pas besoin , pas besoin d'angle non plus pour heros)
    SDL_RenderCopyEx(renderer, heros->texture, &source_rect, &dest_rect, 0, &center, SDL_FLIP_NONE);

    }

}

void drawEnnemi(SDL_Renderer *renderer, Ennemi* ennemi)
{
    //sert a enlever la couleur de fond
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    //drawRect(renderer, (int)ennemi->x, (int)ennemi->y, (int)ennemi->w, (int)ennemi->h);
    int wText, hText;
    //recuepre la taille de la texture
    SDL_QueryTexture(ennemi->texture, NULL, NULL, &wText, &hText);

    if(ennemi->is_boss == true){
        //On defini le rectangle qu'on veut creer dans l'image
        SDL_Rect source_rect = {ennemi->animX*ENNEMI_BOSS_T_WEIGHT, ennemi->animY*ENNEMI_BOSS_T_HEIGHT, ENNEMI_BOSS_T_WEIGHT, ENNEMI_BOSS_T_HEIGHT};
        //On choisi le rectangle qui se situe sur l'ecran
        SDL_Rect dest_rect = {(int)ennemi->x, (int)ennemi->y, (int)ennemi->w, (int)ennemi->t};
        SDL_Point center = {0, 0};
        //Ici flip permet d'inverser les sprites (horinzontal ou vertical , ici pas besoin , pas besoin d'angle non plus pour ennemi)
        SDL_RenderCopyEx(renderer, ennemi->texture, &source_rect, &dest_rect, 0, &center, SDL_FLIP_NONE);

    }else {
        //On defini le rectangle qu'on veut creer dans l'image
        SDL_Rect source_rect = {ennemi->animX*ENNEMI_T_WEIGHT, ennemi->animY*ENNEMI_T_HEIGHT, ENNEMI_T_WEIGHT, ENNEMI_T_HEIGHT};
        //On choisi le rectangle qui se situe sur l'ecran
        SDL_Rect dest_rect = {(int)ennemi->x, (int)ennemi->y, (int)ennemi->w, (int)ennemi->t};

        SDL_Point center = {0, 0};
        //Ici flip permet d'inverser les sprites (horinzontal ou vertical , ici pas besoin , pas besoin d'angle non plus pour ennemi)
        SDL_RenderCopyEx(renderer, ennemi->texture, &source_rect, &dest_rect, 0, &center, SDL_FLIP_NONE);

    }

}


void drawProj(SDL_Renderer* renderer,Projectile* p,SDL_Surface* screenSurface){

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    int wText, hText;
    SDL_QueryTexture(p->texture, NULL, NULL, &wText, &hText);
    SDL_Rect* source_rect = {0, 0, PROJ_T_WEIGHT, PROJ_T_HEIGHT};
    SDL_Rect* dest_rect = {(int)p->x, (int)p->y, (int)p->w, (int)p->t};
    SDL_BlitSurface(p->image,source_rect,screenSurface,dest_rect);

}
