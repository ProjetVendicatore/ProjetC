#include "prototypes.h"
SDL_Renderer* renderer;
//On creer un ennemi
Ennemi* create_ennemi(int y ,int type,SDL_Renderer* renderer)
{
    Ennemi* e=malloc(sizeof(Ennemi));
    e->ennemi_type=type;
    e->ennemi_position.x=STARTING_ENNEMI_X;
    e->ennemi_position.y=y;
    e->is_moving=true;
    e->animX=0;
    //On diff�rencie 4 types d'ennemi , avec des stats diff�rentes.
    if(type == 1) {
        e->is_boss = false;
        e->speed = BASE_ENNEMI_SPEED_TYPE1;
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE1;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE1;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE1;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE1;
        e->ennemi_dimention.x= ENNEMI_T_WEIGHT ;
        e->ennemi_dimention.y= ENNEMI_T_HEIGHT ;
        e->image = SDL_LoadBMP("graphics/ennemi_type1.png");
        SDL_SetColorKey( e->image, SDL_TRUE, SDL_MapRGB(e->image->format, 255, 0, 255));
        e->texture = SDL_CreateTextureFromSurface(renderer, e->image);
        return e ;

     } else if ( type == 2)
     {  e->is_boss = false;
        e->speed = BASE_ENNEMI_SPEED_TYPE2;
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE2;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE2;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE2;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE2;
        e->ennemi_dimention.x= ENNEMI_T_WEIGHT ;
        e->ennemi_dimention.y= ENNEMI_T_HEIGHT ;
        e->image = SDL_LoadBMP("graphics/ennemi_type2.png");
        SDL_SetColorKey( e->image, SDL_TRUE, SDL_MapRGB(e->image->format, 255, 0, 255));
        e->texture = SDL_CreateTextureFromSurface(renderer, e->image);
        return e ;

     } else if ( type == 3)
     {  e->is_boss = false;
        e->speed = BASE_ENNEMI_SPEED_TYPE3;
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE3;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE3;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE3;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE3;
        e->ennemi_dimention.x= ENNEMI_T_WEIGHT ;
        e->ennemi_dimention.y= ENNEMI_T_HEIGHT ;
        e->image = SDL_LoadBMP("graphics/ennemi_type3.png");
        SDL_SetColorKey( e->image, SDL_TRUE, SDL_MapRGB(e->image->format, 255, 0, 255));
        e->texture = SDL_CreateTextureFromSurface(renderer, e->image);
        return e ;

     } else
     {  e->is_boss = true ;
        e->speed = BASE_ENNEMI_SPEED_TYPE3;
        e->base_ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE3;
        e->ennemi_attack = BASE_ENNEMI_DAMAGE_TYPE3;
        e->base_ennemi_life = BASE_ENNEMI_HEALTH_TYPE3;
        e->ennemi_life = BASE_ENNEMI_HEALTH_TYPE3;
        e->ennemi_dimention.x= ENNEMI_T_WEIGHT ;
        e->ennemi_dimention.y= ENNEMI_T_HEIGHT ;
        e->image = SDL_LoadBMP("graphics/Boss.png");
        SDL_SetColorKey( e->image, SDL_TRUE, SDL_MapRGB(e->image->format, 255, 0, 255));
        e->texture = SDL_CreateTextureFromSurface(renderer, e->image);
        return e ;
     }

}




//on detruit un ennemi
void destroy_ennemi(Ennemi* e)
{
    SDL_DestroyTexture(e->texture);
    free(e);
    e=NULL;
}
//on fait des ennemi carr� pour essayer que �a marche
/* void Ennemi_Render(Ennemi* ennemi, SDL_Surface* dest)
{
    if(ennemi != NULL)
    {
        SDL_Rect rect;
        rect.x = ennemi->ennemi_position.x - ennemi->ennemi_dimention.x / 2;
        rect.y = ennemi->ennemi_position.y - ennemi->ennemi_dimention.y / 2;
        rect.w = ennemi->ennemi_dimention.x;
        rect.t = ennemi->ennemi_dimention.y;
        SDL_FillRect(dest, &rect, SDL_MapRGB( dest->format, 0xFF, 0x00, 0x00 ));

        rect.y = ennemi->ennemi_position.y + ennemi->ennemi_dimention.y / 2 + 1;
        rect.t = 2;
        rect.w = ennemi->ennemi_dimention.x * ennemi->ennemi_life / ennemi->base_ennemi_life;
        SDL_FillRect(dest, &rect, SDL_MapRGB( dest->format, 0x00, 0xFF, 0x70 ));
    }
}
*/

//On actualise la position de l'ennemi ( fonction qui le fait bouger )
void update_Ennemi(Ennemi* ennemi, float timeDelta)
{//On check le type pour savoir quel sprite utilis� car le nombres de sprite pour l'animation n'est pa le meme pour tout les ennemis
    if(ennemi != NULL)
    { if (ennemi->ennemi_type == 1)
    //AnimeTime permet de gerer a quel vitesse on charge la prochaine image de l'animation
        {   ennemi->animTime++;
            if(ennemi->animTime > ANIM_SPEED)
            {
            ennemi->animTime = 0;
            ennemi->animX++;
            //Permet de faire la boucle de l'animation
            if(ennemi->animX >= ENNEMI_ANIM_LIMIT_TYPE1)
            {
                ennemi->animX = 0;
            }
        }
            if(ennemi->is_moving == true)
            {
                ennemi->ennemi_position.x -= ennemi->speed* timeDelta;
                //On defini la limite que els ennemi peuvent atteindre
                if(ennemi->ennemi_position.x  >= LIMIT_ENNEMI_X)
                {
                    ennemi->ennemi_position.x= LIMIT_ENNEMI_X;
                    ennemi->is_moving = false;
                }
            }
        }

        else if (ennemi->ennemi_type == 2)
        {   ennemi->animTime++;
            if(ennemi->animTime > ANIM_SPEED)
            {
            ennemi->animTime = 0;
            ennemi->animX++;
            if(ennemi->animX >= ENNEMI_ANIM_LIMIT_TYPE2)
            {
                ennemi->animX = 0;
            }
        }
            if(ennemi->is_moving == true)
            {
                ennemi->ennemi_position.x -= ennemi->speed* timeDelta;
                if(ennemi->ennemi_position.x  >= LIMIT_ENNEMI_X)
                {
                    ennemi->ennemi_position.x= LIMIT_ENNEMI_X;
                    ennemi->is_moving = false;
                }
            }
        } else if (ennemi->ennemi_type == 3)
        {   ennemi->animTime++;
            if(ennemi->animTime > ANIM_SPEED)
            {
            ennemi->animTime = 0;
            ennemi->animX++;
            if(ennemi->animX >= ENNEMI_ANIM_LIMIT_TYPE3)
            {
                ennemi->animX = 0;
            }
        }
            if(ennemi->is_moving == true)
            {
                ennemi->ennemi_position.x -= ennemi->speed* timeDelta;
                if(ennemi->ennemi_position.x  >= LIMIT_ENNEMI_X)
                {
                    ennemi->ennemi_position.x= LIMIT_ENNEMI_X;
                    ennemi->is_moving = false;
                }
            }
        } else
        {   ennemi->animTime++;
            if(ennemi->animTime > ANIM_SPEED)
            {
            ennemi->animTime = 0;
            ennemi->animX++;
            if(ennemi->animX >= ENNEMI_ANIM_LIMIT_BOSS)
            {
                ennemi->animX = 0;
            }
        }
            if(ennemi->is_moving == true)
            {
                ennemi->ennemi_position.x -= ennemi->speed* timeDelta;
                if(ennemi->ennemi_position.x  >= LIMIT_ENNEMI_X)
                {
                    ennemi->ennemi_position.x= LIMIT_ENNEMI_X;
                    ennemi->is_moving = false;
                }
            }
        }
    }
}
