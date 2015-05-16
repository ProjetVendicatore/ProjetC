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
void menu1(Input* input){
    Mouse();
    //Chargement de l'image
    loadImage("graphics/Menu1.png");

    //Si on appuie sur le bouton Play
    if ((x > 300) && (x < 500) && (y > 150) && (y < 190) && input->leftclik == 1){
        menu2(input);

    }
    //Si on appuie sur le bouton Help
    if ((x > 300) && (x < 500) && (y > 220) && (y < 260) && input->leftclik == 1){
        menuHelp(input);

    }
    //Si on appuie sur le bouton Quit
    if ((x > 300) && (x < 500) && (y > 290) && (y < 330) && input->leftclik == 1){
        //Fermer l'application
        exit(0);
    }

}

// PAGE HELP
void menuHelp(Input* input){
    Mouse();
    while (!((x > 500) && (x < 700) && (y > 410) && (y < 440) && input->leftclik == 1)){
        //Chargement de l'image
        loadImage("graphics/MenuHelp.png");
    }
    menu1(input);
}
// MENU 2
void menu2(Input* input){
    Mouse();
    //Chargement de l'image
    loadImage("graphics/Menu2.png");

    //Si on appuie sur le bouton 1
    if ((x > 5) && (x < 10) && (y > 5) && (y < 10) && input->leftclik == 1){
        // Option de personnalisation 1

    }
    //Si on appuie sur le bouton 2
    if ((x > 15) && (x < 20) && (y > 15) && (y < 20) && input->leftclik == 1){
        // Option de personnalisation 1

    }
    //Si on appuie sur le bouton 3
    if ((x > 25) && (x < 30) && (y > 25) && (y < 30) && input->leftclik == 1){
        // Option de personnalisation 1

    }
    //Si on appuie sur le bouton Play
    if ((x > 500) && (x < 700) && (y > 410) && (y < 440) && input->leftclik == 1){
        // Lancer le jeu
        menuGame(input);
    }
}

// MENU JEU
void menuGame(Input* input){
    Mouse();

}
// PAGE GOOD GAME
void menuWin(Input* input){
    while (!((x > 500) && (x < 700) && (y > 410) && (y < 440) && input->leftclik == 1)){
        //Chargement de l'image
        loadImage("graphics/MenuWin.png");
    }
    menu2(input);
}
// PAGE GAME OVER
void menuLose(Input* input){
    while (!(input->leftclik == 1)){
        //Chargement de l'image
        loadImage("graphics/MenuLose.png");
    }
    menu1(input);
}
// Gestion de la pause
void menuBreak(Input* input){
    while (!(input->leftclik == 1)){
        //Chargement de l'image
        loadImage("graphics/MenuBreak.png");
    }
    menuGame(input);
}
