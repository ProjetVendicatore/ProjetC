#include "prototypes.h"
#include "menu.h"

SDL_Event event;

//Les coordonnées de la souris
int x = 0;
int y = 0;

void Mouse(){
//Si la souris a bougé
    if (event.type == SDL_MOUSEMOTION){
        //Recuperation des coordonees de la souris
        x = event.motion.x;
        y = event.motion.y;
    }
}

//Les coordonnées du clic
positionClic.x = event.button.x;
positionClic.y = event.button.y;

// MENU 1
void menuStart(){
    Mouse();
    //Chargement de l'image
    loadImage("graphics/MenuStart.png");

    //Si on appuie sur le bouton Play
    if ((event.button.x > 300) && (event.button.x < 500) && (event.button.y > 150) && (event.button.y < 190) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
        menuGame();

    }
    //Si on appuie sur le bouton Help
    if ((event.button.x > 300) && (event.button.x < 500) && (event.button.y > 220) && (event.button.y < 260) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
        menuHelp();

    }
    //Si on appuie sur le bouton Quit
    if ((event.button.x > 300) && (event.button.x < 500) && (event.button.y > 290) && (event.button.y < 330) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
        //Fermer l'application
        exit(0);
    }

}

// PAGE HELP
void menuHelp(){
    Mouse();
    while (!((event.button.x > 500) && (event.button.x < 700) && (event.button.y > 410) && (event.button.y < 440) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)){
        //Chargement de l'image
        loadImage("graphics/MenuHelp.png");
    }
    menuStart();
}

// MENU JEU
void menuGame(){
    text=TTF_RenderText_Blended(police, "Pause", );
    positionText.x = ;
    positionText.y = ;
    SDL_BlitSurface(text, NULL, SDL_Surface* dst, &positionText);
    SDL_Flip(ecran);
    SDL_Delay(150);
    while (!(event.type == SDL_KEYDOWN && event.button.button == SDL_SCANCODE_SPACE)){
        Mouse();
    }
    menuBreak();
}
// PAGE GOOD GAME
void menuWin(){
    while (!((event.button.x > 500) && (event.button.x < 700) && (event.button.y > 410) && (event.button.y < 440) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)){
        //Chargement de l'image
        loadImage("graphics/MenuWin.png");
    }
    menuGame();
}
// PAGE GAME OVER
void menuLose(){
    while (!(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
        //Chargement de l'image
        loadImage("graphics/MenuLose.png");
    }
    menuStart();
}
// Gestion de la pause
void menuBreak(){
    while (!(event.type == SDL_KEYDOWN && event.button.button == SDL_SCANCODE_SPACE)){
        //Chargement de l'image
        loadImage("graphics/MenuBreak.png");
    }
    menuGame();
}
