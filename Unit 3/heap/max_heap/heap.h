#ifndef HEAP_H
#define HEAP_H
#define MAXSIZE 200
typedef struct heap{
    int key[200];
    int n;
}heap_t;

void init(heap_t *ptr);
void deinit(heap_t *ptr);
void disp(heap_t *ptr);

void build_heap(heap_t *ptr, int a[], int n);




