#ifndef LIST_H_
#define LIST_H_

#include "shared.h"


typedef struct {
    int size;
    Node *HEAD;
    Node *POI;
} List;


List *l_create();
void l_insert(List *list, int value);
void l_remove(List *list);
int l_current(List *list);
void l_begining(List *list);
void l_next(List *list);
int l_is_end(List *list);

#endif