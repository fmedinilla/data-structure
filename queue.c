#include <stdlib.h>
#include "queue.h"


Queue *q_create()
{
    Queue *queue = malloc(sizeof(Queue));

    queue->size = 0;
    queue->HEAD = NULL;
    queue->TAIL= NULL;

    return queue;
}

void q_enqueue(Queue *queue, int value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    if (q_is_empty(queue)) {
        queue->TAIL = node;
        queue->HEAD = node;
    } else {
        queue->TAIL->next = node;
        queue->TAIL = node;
    }

    queue->size++;
}

void q_dequeue(Queue *queue)
{
    Node *aux = queue->HEAD;
    queue->HEAD = queue->HEAD->next;
    free(aux);
    queue->size--;
}

int q_head(Queue *queue)
{
    return queue->HEAD->value;
}

int q_is_empty(Queue *queue)
{
    return queue->HEAD == NULL || queue->TAIL == NULL || queue->size == 0;
}
