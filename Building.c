
#include"prototypes.h"

//On creer un nouveau building
Building* create_building(Vector_2D vect)
{
    Building* b=malloc(sizeof(Building));
    b->building_life = BASE_LIFE_BUILDING ;
    b->base_building_life = BASE_LIFE_BUILDING;
    b->building_pos = vect;

    return b;
}

//On detruit le building
void destroy_building(Building* b)
{
    free(b);
    b = NULL;
}




