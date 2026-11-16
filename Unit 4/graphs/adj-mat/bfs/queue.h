#ifndef queue_h
#define queue_h

typedef struct node{
    int key;
    struct node* next;
}node_t;

typedef struct queue{
    node_t *front;
    node_t *rear;
}queue_t;

void init_queue(queue_t *ptr);
void deinit_queue(queue_t *ptr);
void enqueue(queue_t *ptr, int key);
int dequeue(queue_t *ptr);
int is_empty(queue_t *);
int is_full(queue_t *);

#endif