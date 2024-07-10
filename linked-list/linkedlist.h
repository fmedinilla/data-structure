#ifndef LINKEDLIST_HEADER_
#define LINKEDLIST_HEADER_

typedef struct node_t {
    int value;
    struct node_t *next;
} node_t;

typedef struct {
    node_t *HEAD;
    int size;
} list_t;


node_t *node_create(int value);
void node_destroy(node_t *node);
void node_print(node_t *node);

list_t *list_init();
void *list_destroy(list_t *list);
void list_insert(list_t *list, int value);
void list_remove(list_t *list, int position);

#endif