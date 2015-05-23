#include "prototypes.h"

//Fonction qui permet de savoir si un objet ( une pos) est dans un rectangle défini
bool is_inside_rect(float posX, float posY, float rect_PosX, float rect_PosY, float rect_SizeX, float rect_SizeY)
{
    if(posX > rect_PosX -rect_SizeX / 2.0f && posX < rect_PosX + rect_SizeX / 2.0f && posY > rect_PosY - rect_SizeY / 2.0f && posY < rect_PosY + rect_SizeY / 2.0f)
    {
        return true;
    }
    return false;
}
