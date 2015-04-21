#include "prototypes.h"


void gestionInputs(Input *input)
{
    //On gère le clavier (on rajoutera plus tard la gestion
    //des joysticks)
    getInput(input);
}

 void getInput(Input *input)
 {
     SDL_Event event;
    /* On gere ici la queu d'evenement avec des switch
    On decide d'utiliser seulement les clic de souris (droite et gauche)
    Et 4 touches : un pour pause , 3 pour des sorts/actions
    */
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                exit(0)
            break;
    //ici on fait un switch entre nos 4 touches via key.sym (ID de la touche)
        //Cas ou la touche est enfoncer
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    //On utilise ici SDL_SCANcode au lieu de SDLK pour eviter les problemes de clavier FR ou EN
                case SDL_SCANCODE_SPACE:
                    input->pause = 1;

                case SDL_SCANCODE_A:
                    input->firstspell = 1;
                case SDL_SCANCODE_Z:
                    input->secondspell = 1;
                case SDL_SCANCODE_E:
                    input->thirdspell =1;
                    default:break;
                }
            break;
        //Cas ou la touche est non enfoncer
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDL_SCANCODE_SPACE:
                    input->pause = 0;

                case SDL_SCANCODE_A:
                    input->firstspell = 0;
                case SDL_SCANCODE_Z:
                    input->secondspell = 0;
                case SDL_SCANCODE_E:
                    input->thirdspell =0;
                    default:break;
                }
            break;

            case SDL_MOUSEBUTTONDOWN:
                switch (event.button)
                {
                //Clik gauche
                case SDL_BUTTON(1):
                input->leftclik = 1;
                //Clik droit
                case SDL_BUTTON(3):
                input->rightclik = 1;
                default:break;
                }
                break;

            case SDL_MOUSEBUTTONUP:
                switch (event.button)
                {
                //Clik gauche
                case SDL_BUTTON(1):
                input->leftclik = 0;
                //Clik droit
                case SDL_BUTTON(3):
                input->rightclik = 0 ;
                default:break;
                }
            break;

        }


    }

 }

