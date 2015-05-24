#include "prototypes.h"

//Création d'un vecteur


//Addition de deux vecteurs

Vector_2D vector_addition(Vector_2D Vector1, Vector_2D Vector2)
{
    Vector_2D result;
    result.x = Vector1.x + Vector2.x;
    result.y = Vector1.y + Vector2.y;
    return result;
}

// Soustraction de deux vecteurs
Vector_2D vector_subtraction(Vector_2D vector1 , Vector_2D vector2)
{
  Vector_2D result;
    result.x = vector1.x - vector2.x;
    result.y = vector1.y - vector2.y;
    return result;

}


Vector_2D vector_normalize(Vector_2D Vector)
{
    Vector_2D result;
    float norm = sqrt(Vector.x * Vector.x + Vector.y * Vector.y);
    result.x = Vector.x / norm;
    result.y = Vector.y / norm;
    return result;
}


Vector_2D vector_multiply(Vector_2D Vector, float value)
{
    Vector_2D result;
    result.x = Vector.x * value;
    result.y = Vector.y * value;
    return result;
}

Vector_2D* create_vector(float x ,float y)
{
    Vector_2D* p=malloc(sizeof(Vector_2D));
    p->x=x;
    p->y=y;

    return p;
}


