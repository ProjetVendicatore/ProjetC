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
        SDL_QUIT();
    }
}

// PAGE HELP
void menuHelp(){
    while (!((x > 500) && (x < 700) && (y > 410) && (y < 440) && leftclik == 1)){
        //Chargement de l'image
        loadImage("graphics/MenuHelp.png");
    }
    menu1();
}
// MENU 2
void menu2(){
    //Chargement de l'image
    loadImage("graphics/Menu2.png");

    //Si on appuie sur le bouton 1
    if ((x > x1) && (x < x2) && (y > y1) && (y < 2) && leftclik == 1){
        // Option de personnalisation 1

    }
    //Si on appuie sur le bouton 2
    if ((x > x1) && (x < x2) && (y > y1) && (y < 2) && leftclik == 1){
        // Option de personnalisation 1

    }
    //Si on appuie sur le bouton 3
    if ((x > x1) && (x < x2) && (y > y1) && (y < 2) && leftclik == 1){
        // Option de personnalisation 1

    }
    //Si on appuie sur le bouton Play
    if ((x > 500) && (x < 700) && (y > 410) && (y < 440) && leftclik == 1){
        // Lancer le jeu
        menuGame();
    }
}

// MENU JEU
void menuGame(){

}
// PAGE GOOD GAME
void menuWin(){

}
// PAGE GAME OVER
void menuLose(){
    while (!(leftclik == 1)){
        //Chargement de l'image
        loadImage("graphics/MenuLose.png");
    }
    menu1();
}
// Gestion de la pause
void menuBreak(){
    while (!(leftclik == 1)){
        //Chargement de l'image
        loadImage("graphics/MenuLose.png");
    }
    menuGame();
}
