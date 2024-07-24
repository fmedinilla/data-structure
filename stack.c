#include <stdlib.h>
#include "stack.h"


Stack *s_create()
{
    Stack *stack = malloc(sizeof(Stack));

    stack->size = 0;
    stack->HEAD = NULL;

    return stack;
}

void s_stack(Stack *stack, int value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = stack->HEAD;
    stack->HEAD = node;
    stack->size++;
}

void s_unstack(Stack *stack)
{
    Node *aux = stack->HEAD;
    stack->HEAD = aux->next;
    stack->size--;
    free(aux);
}

int s_top(Stack *stack)
{
    return stack->HEAD->value;
}

int s_is_empty(Stack *stack)
{
    return stack->HEAD == NULL || stack->size == 0;
}
