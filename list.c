#include <stdlib.h>
#include "list.h"


List *l_create()
{
    List *list = malloc(sizeof(List));

    list->size = 0;
    list->HEAD = NULL;
    list->POI = list->HEAD;

    return list;
}

void l_insert(List *list, int value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    if (list->size == 0) {
        list->HEAD = node;
        list->POI = list->HEAD;
    } else {
        Node *aux =  list->HEAD;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = node;
    }

    list->size++;
    list->POI = node;
}

void l_remove(List *list)
{
    Node *aux = list->HEAD;

    Node *prev = list->HEAD;
    while(aux != NULL && aux != list->POI) {
        prev = aux;
        aux = aux->next;
    }

    // here aux is POI or NULL
    if (aux == NULL) return;

    // here aux is POI
    if (aux == prev) {
        aux = aux->next;
    }

    if (prev == list->POI) {
        list->HEAD = prev->next;
        list->POI = prev->next;
        free(prev);
    } else {
        prev->next = list->POI->next;
        if (aux->next == NULL) {
            list->POI = list->HEAD;
        } else {
            list->POI = aux->next;
        }
        free(aux);
    }

    list->size--;
}

int l_current(List *list)
{
    return list->POI->value;
}

void l_begining(List *list)
{
    list->POI = list->HEAD;
}

void l_next(List *list)
{
    if (list->POI->next != NULL) {
        list->POI = list->POI->next;
    } else {
        list->POI = list->HEAD;
    }
}

int l_is_end(List *list)
{
    return list->POI->next == NULL;
}
