#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <stdlib.h>

typedef struct lNode lNode;

struct lNode
{
void* p_elem;
lNode* p_next;
};

typedef struct lList lList;

struct lList
{
int elemCount;
lNode* p_head;
lNode* p_tail;
};

lList* lList_create();

void lList_destroy(lList* _list);

void lList_append(lList* _list, void* _newElem);

void lList_prepend(lList* _list, void* _newElem);

void lList_remove(lList* _list, void* _elem);

void lList_Show(lList* _list, char* _type);

void lList_append(lList* _list, void* _newElem)
{
if(_list != NULL)
{
lNode* newNode = malloc(sizeof(lNode));
newNode->p_next = NULL;
newNode->p_elem = _newElem;
if(_list->p_tail != NULL)
{
_list->p_tail->p_next = newNode;
}
if(_list->p_head == NULL)
{
_list->p_head = newNode;
}
_list->p_tail = newNode;
_list->elemCount++;
}
}


void lList_Show(lList* _list, char* _type)
{
if(_list != NULL)
{
printf("il y a %d %s dans la liste. l'element en tete est : %d, l'element en fin est : %d\n", _list->elemCount, _type, _list->p_head, _list->p_tail);
}
}
#endif // LINKEDLIST_H_INCLUDE
