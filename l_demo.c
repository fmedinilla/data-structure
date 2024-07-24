#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main(void)
{
    List *list = l_create();

    l_insert(list, 3);
    l_insert(list, 5);

    int v = l_current(list);
    printf("Current: %d\n", v);

    l_insert(list, 7);
    l_insert(list, 9);

    l_remove(list);
    l_begining(list);
    l_remove(list);

    l_insert(list, 2);
    l_begining(list);
    l_next(list);
    l_remove(list);

    l_begining(list);
    while (!l_is_end(list)) {
        int value = l_current(list);
        printf("value: %d\n", value);
        l_next(list);
    }
    int value = l_current(list);
    printf("value: %d\n", value);

    Node *aux = list->HEAD;
    while (aux != NULL) {
        Node *temp = aux;
        aux = aux->next;
        free(temp);
    }
    free(list);

    return 0;
}
