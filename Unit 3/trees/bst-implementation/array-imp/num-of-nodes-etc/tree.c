#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void init(tree_t *ptr){
    ptr->root = -1;
    ptr->count = 0;
}


void deinit(tree_t *ptr){
    ptr->root = -1;
    ptr->count = 0;
}

static int insert_recursive(node_t elem[], int root, int temp){
    if(root == -1){
        root = temp;
    }
    else if(elem[root].key>elem[temp].key){
        elem[root].left = insert_recursive(elem,elem[root].left, temp);
        
    }
    else if(elem[root].key<elem[temp].key){
        elem[root].right = insert_recursive(elem, elem[root].right,temp);
    }
    return root;
    
}

void insert(tree_t *ptr, int key){
    if(ptr->count == MAXSIZE){
        printf("\nTree is full. \n");exit(1);
    }
    int temp = ptr->count ++;
    ptr->elem[temp].key = key;
    ptr->elem[temp].left = ptr->elem[temp].right = -1;
    ptr->root = insert_recursive(ptr->elem,ptr->root,temp);
}

static void disp_recursive(node_t elem[],int temp){
    if(temp!=-1){
        disp_recursive(elem,elem[temp].left);
        printf("%d ", elem[temp].key);
        disp_recursive(elem,elem[temp].right);
    }
}
void display(tree_t *ptr){
    printf("Tree: ");
    disp_recursive(ptr->elem, ptr->root);
    printf("\n");
}

static int num_nodes_recursive(node_t elem[], int temp){
    if(temp == -1){
        return 0;
    }
    else{
        return 1 + num_nodes_recursive(elem,elem[temp].left) 
        + num_nodes_recursive(elem, elem[temp].right);
    }
}

static int num_leaves_recursive(node_t elem[], int temp){
    if(temp==-1) return 0;
    else if(elem[temp].left == -1 && elem[temp].right == -1){
        return 1;
    }
    else{
        return num_leaves_recursive(elem, elem[temp].left)
         + num_leaves_recursive(elem,elem[temp].right);
    }
}

int num_nodes(tree_t *ptr){
    return num_nodes_recursive(ptr->elem, ptr->root);
}
int num_leaves(tree_t *ptr){
    return num_leaves_recursive(ptr->elem, ptr->root);
}
