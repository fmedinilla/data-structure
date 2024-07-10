#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

node_t *node_create(int value)
{
    node_t *node = malloc(sizeof(node_t));
    printf("[NODE] created at 0x%p\n", node);
    node->next = NULL;
    node->value = value;
    return node;
}
void node_destroy(node_t *node)
{
    printf("[NODE] destroy at 0x%p\n", node);
    free(node);
}
void node_print(node_t *node)
{
    printf(
        "Node { at: 0x%p\tvalue: %d\tnext: 0x%p }\n",
        node,
        node->value,
        node->next
    );
}

list_t *list_init()
{
    list_t *list = malloc(sizeof(list_t));
    printf("[LIST] created at 0x%p\n", list);
    
    list->HEAD = NULL;
    list->size = 0;

    return list;
}
void *list_destroy(list_t *list)
{
    node_t *aux = list->HEAD;
    while (aux != NULL) {
        node_t *temp = aux;
        aux = aux->next;
        node_destroy(temp);
    }
    
    printf("[LIST] destroy at 0x%p\n", list);
    free(list);
}
void list_insert(list_t *list, int value)
{
    node_t *node = node_create(value);

    if (list->size == 0) {
        list->HEAD = node;
    } else {
        node_t *last = list->HEAD;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = node;
    }

    list->size++;
}
void list_remove(list_t *list, int position)
{
    if (position >= list->size) return;

    node_t *aux = list->HEAD;
    node_t *prev = NULL;
    int counter = 0;
    while (aux->next != NULL && counter != position) {
        prev = aux;
        aux = aux->next;
        counter++;
    }
    prev->next = aux->next;
    node_destroy(aux);
}
