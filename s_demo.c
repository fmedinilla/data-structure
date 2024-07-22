#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* ENTRY POINT */
int main(void)
{
    Stack *stack = s_create();

    printf("Stack size: %d\n", stack->size);
    printf("Stack HEAD addr: %p\n", stack->HEAD);

    printf("is_empty: %d\n", s_is_empty(stack));

    s_stack(stack, 3);
    s_stack(stack, 5);
    s_stack(stack, 7);

    printf("is_empty: %d\n", s_is_empty(stack));

    int v = s_top(stack);
    printf("Top item: %d\n", v);
    s_unstack(stack);

    // print stack
    Node *aux = stack->HEAD;
    while (aux != NULL) {
        printf("Stack Item { addr: %p, value: %d, next: %p}\n", aux, aux->value, aux->next);
        aux = aux->next;
    }

    // Free all resources
    aux = stack->HEAD;
    while (aux != NULL) {
        Node *temp = aux;
        aux = aux->next;
        free(temp);
    }
    free(stack);

    // return value
    return 0;
}
