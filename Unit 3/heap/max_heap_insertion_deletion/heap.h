#ifndef HEAP_H
#define HEAP_H

#define MAXSIZE 200

typedef struct heap heap_t;

struct heap{
    int key[MAXSIZE];
    int n;
};

void init(heap_t *ptr);
void deinit(heap_t *ptr);
void disp(heap_t *ptr);

void build_heap(heap_t *ptr, int a[], int n);
int delete_max(heap_t *ptr);
int peek_max(heap_t *ptr);

void insert(heap_t *ptr, int key);

#endif



