#include "prototypes.h"
SDL_Window* window;
SDL_Renderer* renderer;
lList* ennemiList ;
lList* bulletList ;
Vector_2D mousePosition;
SDL_Rect HPTextPosition;
SDL_Surface* HPText;
int HP ;
TTF_Font* police;

void UpdateHPText()
{
    HP = 50 ;
    char result[20];
    sprintf(result,"HP : %d", HP);
    SDL_Color color = {0, 0, 0};
    HPText = TTF_RenderUTF8_Blended(police, result, color);
}

void Render()
{
//Get window surface
SDL_Surface* screenSurface = SDL_GetWindowSurface( window );

//Fill the surface white
SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

if(ennemiList != NULL)
{
lNode* ennemiNode = ennemiList->p_head;
while(ennemiNode)
{
Ennemi* ennemi = (Ennemi*)ennemiNode->p_elem;
drawEnnemi(renderer,ennemi);
ennemiNode = ennemiNode->p_next;
}
}

if(bulletList != NULL)
{
lNode* bulletNode = bulletList->p_head;
while(bulletNode)
{
Projectile* projectile = (Projectile*)bulletNode->p_elem;
drawProj(renderer,projectile,screenSurface);
bulletNode = bulletNode->p_next;
}
}

SDL_Rect mouseCursor;
mouseCursor.x = mousePosition.x - 5;
mouseCursor.y = mousePosition.y - 5;
mouseCursor.w = 10;
mouseCursor.h = 10;
SDL_FillRect( screenSurface, &mouseCursor, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0x00 ) );

SDL_Rect caracter;
caracter.x = 8 - 10;
caracter.y = 480/2 - 10;
caracter.w = 20;
caracter.h = 20;
SDL_FillRect( screenSurface, &caracter, SDL_MapRGB( screenSurface->format, 0x0, 0xFF, 0x0 ) );

HPTextPosition.x = 560;
HPTextPosition.y = 5;
SDL_BlitSurface(HPText,NULL, screenSurface, &HPTextPosition);
//Update the surface
SDL_UpdateWindowSurface( window );

}

//Renderer Ennemi



