#ifndef STACK_H_
#define STACK_H_

#include "shared.h"

typedef struct {
    int size;
    Node *HEAD;
} Stack;


Stack *s_create();
void s_stack(Stack *stack, int value);
void s_unstack(Stack *stack);
int s_top(Stack *stack);
int s_is_empty(Stack *stack);

#endif
