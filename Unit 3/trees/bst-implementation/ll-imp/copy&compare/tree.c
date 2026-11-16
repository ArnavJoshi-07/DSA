#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


void init(tree_t *ptr){
    ptr->root = NULL;
}

static void deinit_recursive(node_t *temp){
    if(temp){
        deinit_recursive(temp->left);
        deinit_recursive(temp->right);
        free(temp);
    }
}

void deinit(tree_t *ptr){
    deinit_recursive(ptr->root);
    ptr->root = NULL;
}

static void disp_recursive(node_t *temp){
    if(temp){
        disp_recursive(temp->left);
        printf("%d ", temp->key);
        disp_recursive(temp->right);
    }
}

void disp(tree_t *ptr){
    printf("TREE: ");
    disp_recursive(ptr->root);
    printf("\n");
}

static node_t* insert_recursive(node_t *root, node_t *temp){
    if(root == NULL){
        root = temp;
    }
    else if(root->key > temp->key){
        root->left = insert_recursive(root->left, temp);
    }
    else if(root->key < temp->key){
        root->right = insert_recursive(root->right, temp);
    }
    return root;
}

void insert(tree_t *ptr, int key){
    node_t *temp = malloc(sizeof(node_t));
    temp->key = key;
    temp->left = temp->right = NULL;
    ptr->root = insert_recursive(ptr->root, temp);
}

static int num_nodes_recursive(node_t *temp){
    if(temp==NULL) return 0;
    else{
        return 1 + num_nodes_recursive(temp->left) + num_nodes_recursive(temp->right);
    }
}

static int num_leaves_recursive(node_t *temp){
    if(temp==NULL) return 0;
    else if(temp->left == NULL && temp->right == NULL){
        return 1;
    }
    else{
        return num_leaves_recursive(temp->left) 
        + num_leaves_recursive(temp->right);
    }
}

static node_t* copy_recursive(node_t *src){
    node_t *temp;
    if(src!=NULL){
        temp = (node_t *)malloc(sizeof(node_t));
        temp->key = src->key;
        temp->left = copy_recursive(src->left);
        temp->right = copy_recursive(src->right);
        return temp;
    }
    else{
        return NULL;
    }
}
void copy(tree_t *src, tree_t *dest){
    dest->root = copy_recursive(src->root);
}

static int compare_recursive(node_t * src, node_t *dest){
    if(src == NULL && dest == NULL) return 1;
    else if(src == NULL || dest == NULL) return 0;
    else{
        return src->key == dest->key && 
        compare_recursive(src->left, dest->right) &&
        compare_recursive(src->right, dest->right);
    }
}

int compare(tree_t *src, tree_t *dest){
    return compare_recursive(src->root, dest->root);
}
