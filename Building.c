
#include"prototypes.h"

Building* create_building(int life,int def)
{
    Building* b = malloc(sizeof(Building));
    b->building_life = life ;
    b->building_def = def ;
}
