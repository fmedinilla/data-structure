#ifndef QUEUE_H_
#define QUEUE_H_

#include "shared.h"


typedef struct {
    int size;
    Node *HEAD;
    Node *TAIL;
} Queue;


Queue *q_create();
void q_enqueue(Queue *queue, int value);
void q_dequeue(Queue *queue);
int q_head(Queue *queue);
int q_is_empty(Queue *queue);

#endif
