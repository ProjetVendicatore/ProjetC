#include "prototypes.h"

//On creer une liste chainé , composé de maillon (lNode)
lList* lList_create()
{
    lList* newList = malloc(sizeof(lList));
    newList->elemCount = 0;
    newList->p_head = NULL;
    newList->p_tail = NULL;
    return newList;
}

//On detruit la liste
void destroy_lList(lList* liste)
{
    if(liste != NULL)
    {
        lNode* p_next = liste->p_head;
        while(p_next != NULL)
        {
            lNode* toDelete = p_next;
            p_next = p_next->p_next;
            free(toDelete->p_elem);
            free(toDelete);
        }
        free(liste);
    }
}

//On ajoute un maillon dans la liste
void lList_append(lList* liste, void* new_elem)
{
    if(_list != NULL)
    {
        lNode* newNode = malloc(sizeof(lNode));
        newNode->p_next = NULL;
        newNode->p_elem = new_elem;
        if(liste->p_tail != NULL)
        {
            liste->p_tail->p_next = newNode;
        }
        if(liste->p_head == NULL)
        {
            liste->p_head = newNode;
        }
        liste->p_tail = newNode;
        liste->elemCount++;
    }
}
//On ajout un maillon en tete de liste
void lList_prepend(lList* liste, void* new_elem)
{
    if(liste != NULL)
    {
        lNode* newNode = malloc(sizeof(lNode));
        newNode->p_next = liste->p_head;
        newNode->p_elem = new_elem;
        liste->p_head = newNode;
        liste->elemCount++;
    }
}

//On enleve un maillon de la liste
void lList_remove(lList* _list, void* _elem)
{
    if(_list != NULL)
    {
        lNode* p_previous = NULL;
        lNode* p_current = _list->p_head;
        while(p_current)
        {
            if(p_current->p_elem == _elem)
            {
                if(p_previous != NULL)
                {
                    p_previous->p_next = p_current->p_next;
                }
                else
                {
                    _list->p_head = p_current->p_next;
                }
                if(p_current->p_next == NULL)
                {
                    _list->p_tail = p_previous;
                }
                free(p_current);
                _list->elemCount--;
                p_current = NULL;
            }
            else
            {
                p_previous = p_current;
                p_current = p_current->p_next;
            }
        }
    }
}

//Test pour voir comment se comporte notre liste chainé
void lList_Show(lList* _list, char* _type)
{
    if(_list != NULL)
    {
        printf("il y a %d %s dans la liste. l'element en tete est : %d, l'element en fin est : %d\n", _list->elemCount, _type, _list->p_head, _list->p_tail);
    }
}
