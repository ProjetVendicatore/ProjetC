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

// MENU 1
void menuStart(){
    Mouse();
    //Chargement de l'image
    loadImage("graphics/MenuStart.png");

    //Si on appuie sur le bouton Play
    if ((x > 300) && (x < 500) && (y > 150) && (y < 190) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
        menuGame();

    }
    //Si on appuie sur le bouton Help
    if ((x > 300) && (x < 500) && (y > 220) && (y < 260) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
        menuHelp();

    }
    //Si on appuie sur le bouton Quit
    if ((x > 300) && (x < 500) && (y > 290) && (y < 330) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
        //Fermer l'application
        exit(0);
    }

}

// PAGE HELP
void menuHelp(){
    Mouse();
    while (!((x > 500) && (x < 700) && (y > 410) && (y < 440) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)){
        //Chargement de l'image
        loadImage("graphics/MenuHelp.png");
    }
    menuStart();
}

// MENU JEU
void menuGame(){
    while (!((x > 0) && (x < 200) && (y > 450) && (y < 480) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)){
        Mouse();
    }
    menuBreak();
}
// PAGE GOOD GAME
void menuWin(){
    while (!((x > 500) && (x < 700) && (y > 410) && (y < 440) && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)){
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
    while (!(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)){
        //Chargement de l'image
        loadImage("graphics/MenuBreak.png");
    }
    menuGame();
}
