#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

static node_t * leftmost(node_t *temp){
    if(temp == NULL) return NULL;
    while(temp->lthread == 0) //actual left child exists
    {
        temp = temp->left;
    }
    return temp;
}

static void inorder(node_t *root){
    node_t *temp = leftmost(root);
    while(temp!=NULL){
        printf("%d ",temp->key);
        //no right child exists but points to inorder successor
        if(temp->rthread == 1) temp= temp->right; 
        else temp = leftmost(temp->right); 
        //find the inorder successor if it doesnt point to it alr.
    }
}

void init(tree_t *ptr){
    ptr->root = NULL;
}

void deinit(tree_t *ptr){
    node_t *temp = leftmost(ptr->root);
    node_t *pres;
    while(temp!=NULL){
        pres = temp;
        if(temp->rthread == 1) temp = temp->right; //if rthread == 1, the right pointer directly points to inorder successor.
        else temp = leftmost(temp->right); // if rthread != 1, then find the leftmost node of the right subtree.
        free(pres);
    }
    ptr->root = NULL;
}

void disp(tree_t *ptr){
    printf("Tree : ");
    inorder(ptr->root);
    printf("\n");
}

static node_t *create_node(int key){
    node_t *temp = malloc(sizeof(node_t));
    if(temp == NULL) {printf("\nMemory not available.\n"); exit(1);}
    
    temp->key = key;
    temp->right = temp->left = NULL;
    temp->lthread = temp->rthread = 1;
    return temp;
}

static node_t * insert_key(node_t *root, int key){
    node_t *temp = create_node(key);
    if(root == NULL) return temp;

    node_t * parent = NULL;
    node_t *curr = root;
    while(curr!=NULL){
        parent = curr;
        if(key < curr->key){
            if(curr->lthread == 0) curr = curr->left;
            else break;
        }
        else{
            if(curr->rthread == 0) curr = curr->right;
            else break;
        }
    }
    //inserting as left child
    if(key<parent->key) {
        temp->left = parent->left;
        temp->right = parent;
        parent->left = temp;
        parent->lthread = 0;
    }

    //inserting as right child 
    if(key>parent->key){
        temp->right = parent->right;
        temp->left = parent;
        parent->right = temp;
        parent->rthread = 0;
    }
    return root;
}

void insert(tree_t *ptr,int key){
    ptr->root = insert_key(ptr->root, key);
}