#include "prototypes.h"

Position* create_position(int x ,int y)
{
    Position* p=malloc(size(Position));
    p->x=x;
    p->y=y;
    return p;
}

void uptdate_position(Position p,int x, int y )
{
    p->x=x ;
    p->y=y ;
    return ;
}
