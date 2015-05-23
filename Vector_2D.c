#include "prototypes.h"

//Création d'un vecteur


//Addition de deux vecteurs

Vector_2D Vector2D_addition(Vector2D Vector1, Vector2D Vector2)
{
    Vector2D result;
    result.x = Vector1.x + Vector2.x;
    result.y = Vector1.y + Vector2.y;
    return result;
}

// Soustraction de deux vecteurs
Vector_2D vector_subtraction(Vector_2D vector1 , Vector_2D vector2)
{
  Vector2D result;
    result.x = Vector1.x - Vector2.x;
    result.y = Vector1.y - Vector2.y;
    return result;

    return v ;
}


Vector_2D vector_normalize(Vector2D _Vector)
{
    Vector_2D result;
    float norm = sqrt(Vector.x * Vector.x + Vector.y * Vector.y);
    result.x = Vector.x / norm;
    result.y = Vector.y / norm;
    return result;
}


Vector_2D vector_multiply(Vector2D Vector, float value)
{
    Vector2D result;
    result.x = Vector.x * value;
    result.y = Vector.y * value;
    return result;
}
Vector_2D create_vector(float x ,float y)
{
    Vector_2D* p=malloc(sizeof(Vector_2D));
    p->x=x;
    p->y=y;

    return p;
}


