#include "prototypes.h"
#include "menu.h"

SDL_Event event;

//Les coordonnées de la souris
int x = 0, y = 0;

//Si la souris a bougé
if( event.type == SDL_MOUTEMOTION){
    //Recuperation des coordonees de la souris
    x = event.motion.x;
    y = event.motion.y;
    }

// MENU 1
void menu1(){
    //Chargement de l'image
    loadImage("graphics/Menu1.png");

    //Si on appuie sur le bouton Play
    if ((x > 300) && (x < 500) && (y > 150) && (y < 190) && leftclik == 1){
        menu2();

    }
    //Si on appuie sur le bouton Help
    if ((x > 300) && (x < 500) && (y > 220) && (y < 260) && leftclik == 1){
        menuHelp();

    }
    //Si on appuie sur le bouton Quit
    if ((x > 300) && (x < 500) && (y > 290) && (y < 330) && leftclik = 1){
        //Fermer l'application

    }
}

// PAGE HELP
void menuHelp(){
    while (!((x > 300) && (x < 500) && (y > 150) && (y < 190) && leftclik == 1)){
        menu2()
    //Chargement de l'image
    loadImage("graphics/Menu1.png");

    //Si on appuie sur le bouton Play
    if ((x > 300) && (x < 500) && (y > 150) && (y < 190) && leftclik == 1){
        menu2();

    }
}
// MENU 2
void menu2(){

}

// MENU JEU
void menuGame(){

}
// PAGE GOOD GAME
void menuWin(){

}
// PAGE LOST GAME
void menuLose(){

}
// Gestion de la pause
void menuBreak(){

}
