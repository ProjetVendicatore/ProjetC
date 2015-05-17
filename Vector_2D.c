#include "prototypes.h"

//Addition de deux vecteurs
Vector_2D vector_addition(Vector_2D vector1 , Vector_2D vector2)
{
    Vector_2D v;

    v.x =(vector1.x + vector2.x) ;
    v.y =(vector1.y + vector2.y) ;

    return v ;
}

// Soustraction de deux vecteurs
Vector_2D vector_subtraction(Vector_2D vector1 , Vector_2D vector2)
{
   Vector_2D v;

    v.x=(vector1.x - vector2.x) ;
    v.y=(vector1.y - vector2.y) ;

    return v ;
}

//Longueur d'un vecteur
float vector_length(Vector_2D vector1)
{
    float l = 0;

    l=sqrtf( powf(vector1.x,2)+ powf(vector1.y,2) );

    return l;
}

//Normalisation d'un vecteur
Vector_2D vector_normalize(Vector_2D vector1)
{
    Vector_2D v;

    v.x = (vector1.x / vector_length(vector1));
    v.y = (vector1.y / vector_length(vector1));

    return v;
}

//Multiplication d'un vecteur avec un coeff
Vector_2D vector_multiply(Vector_2D vector1,float coeff)
{
   Vector_2D v;

    v.x = (vector1.x*coeff);
    v.y = (vector1.y*coeff);

    return v;
}



