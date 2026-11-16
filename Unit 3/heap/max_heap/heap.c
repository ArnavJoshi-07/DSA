#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void init(heap_t *ptr){
    ptr->n = 0;
}

void deinit(heap_t *ptr){
    ptr->n = 0;
}

void disp(heap_t *ptr){
    int j = ptr->n;
    for(int i = 1; i<=j;i++){
        printf("%d ", ptr->key[i]);
    }
}

void build_heap(heap_t *ptr, int a[], int n){
    //bottom-up heap construction

    //every leaf node is alr a heap.
    /*
    left child = 2i
    right child = 2i + 1

    a node is a leaf if it doesnt have a left child. 

    for a heap with n elements, 2i > n. Therefore i > n/2
    that means elements after n/2 are all leafs. 
    as leafs obey the parental dominance property automatically, we will only traverse upto n/2

    the last non leaf node is at n/2
    Every leaf node is already a heap.
    */
    ptr->n = n;
    for(int i = 1; i<=n; i++) //i>=1 because we are implementing a 1-indexed array, not a 0-indexed array.
    {
        ptr->key[i] = a[i];
    }
    for(int i = n/2; i>=1; --i){
        heapify(ptr->key, ptr->n, i);
        disp(ptr);
    }
}

static void heapify(int a[], int n, int pos){
    int i = pos;
    int j = 2*i;
    int val = a[i];
    int is_heap = 0;
    while(j<=n && !is_heap) //while a left child exists and the subtree is not a heap
    {
        if(j+1 <= n && a[j+1]>a[j])  j++;//if right child exists and is the greater child between the two, the point to the right child, or default points to the left one

        if(a[j]>val){
            //if the child is greater than the root
            a[i] = a[j]; //swap the root and the child
            i = j;
            j = 2*i; // larger child is moved upwards
        }
        else{
            //none of the children are greater than the root.. that means subtree is a heap
            is_heap = 1;
        }
    }   

}
