#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* ENTRY POINT */
int main(void)
{
    Queue *queue = q_create();

    printf("Queue size: %d\n", queue->size);
    printf("Queue HEAD addr: %p\n", queue->HEAD);
    printf("Queue TAIL addr: %p\n", queue->TAIL);

    printf("Is empty? %d\n", q_is_empty(queue));

    q_enqueue(queue, 3);
    q_enqueue(queue, 5);
    q_enqueue(queue, 7);

    printf("Is empty? %d\n", q_is_empty(queue));

    int h = q_head(queue);
    printf("Head value: %d\n", h);
    q_dequeue(queue);

    Node *aux = queue->HEAD;
    while (aux != NULL) {
        printf("Queue Item { addr: %p, value: %d, next: %p }\n", aux, aux->value, aux->next);
        aux = aux->next;
    }

    // free resources
    aux = queue->HEAD;
    while (aux != NULL) {
        Node *temp = aux;
        aux = aux->next;
        free(temp);
    }
    free(queue);

    // return value
    return 0;
}
