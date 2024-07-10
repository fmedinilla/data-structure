#include <stdio.h>
#include "linkedlist.h"

int main(void)
{
    list_t *list = list_init();

    list_insert(list, 3);
    list_insert(list, 5);
    list_insert(list, 7);

    node_t *aux;

    puts("List:");
    aux = list->HEAD;
    while (aux != NULL) {
        node_print(aux);
        aux = aux->next;
    }

    list_remove(list, 1);

    puts("List:");
    aux = list->HEAD;
    while (aux != NULL) {
        node_print(aux);
        aux = aux->next;
    }

    list_destroy(list);
    return 0;
}
