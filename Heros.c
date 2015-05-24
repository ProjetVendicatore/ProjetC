#include "prototypes.h"

//on creer notre Heros
Heros* create_heros(SDL_Renderer* renderer)
{
    Heros* h=malloc(sizeof(Heros));
    h->heros_attack = BASE_HEROS_DAMAGE;
    h->base_heros_attack = BASE_HEROS_DAMAGE;
    h->image = SDL_LoadBMP("graphics/heros.png");
    SDL_SetColorKey( h->image, SDL_TRUE, SDL_MapRGB(h->image->format, 255, 0, 255));
    h->texture = SDL_CreateTextureFromSurface(renderer, h->image);
    h->x =INIT_POS_X_HEROS;
    h->y=INIT_POS_Y_HEROS;
    h->t=HEROS_T_HEIGHT;
    h->w=HEROS_T_WEIGHT;
    h->is_shooting = false;
    h->animX=0;
    h->animY=0;
    h->animTime=0;
    return h;
}

//On detruit notre heros
void destroy_heros(Heros* h)
{
    SDL_DestroyTexture(f->texture);
    free(h);
    h=NULL;
}

//Fonction qui permet d'up notre heros
void upgrade_heros_damage(Heros* h)
{
    h->heros_attack = h.heros_attack + COEFF_HEROS_UPGRADE_DAMAGE ;
    return;
}

void update_heros(Heros* h,float timeDelta){
    if (h->is_shooting == true) {
            //AnimY*HEROS WEIGHT dans le draw
        h->animY = 1;
        h->animTime++;
        if(h->animTime > ANIM_SPEED)
        {
            h->animTime = 0;
            h->animX++;
            if(h->animX >= HEROS_ANIM_SHOOTING_LIMIT)
            {
                h->animX = 0;
            }
        }
    }else{
        h->animY = 0;
        h->animTime++;
            if(h->animTime > ANIM_SPEED)
            {
                h->animTime = 0;
                h->animX++;
                if(h->animX >= HEROS_ANIM_LIMIT)
                {
                    h->animX = 0;
                }
            }
        }
}



