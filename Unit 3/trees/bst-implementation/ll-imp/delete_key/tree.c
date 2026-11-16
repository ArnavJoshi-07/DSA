#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void init(tree_t *ptr){
    ptr->root = NULL;
}

static void deinit_recursive(node_t *ptr){
    if(ptr){
        deinit_recursive(ptr->left);
        deinit_recursive(ptr->right);
        free(ptr);
    }
}

void deinit(tree_t *ptr){
    deinit_recursive(ptr->root);
}

static void disp_inorder_recursive(node_t *temp){
    if(temp){
        disp_inorder_recursive(temp->left);
        printf("%d ",temp->key);
        disp_inorder_recursive(temp->right);
    }
}

void disp_inorder(tree_t *ptr){
    disp_inorder_recursive(ptr->root);
}


static node_t * insert_recursive(node_t *ptr, node_t *temp){
    if(ptr == NULL) ptr = temp;
    else if(ptr->key > temp->key){
        ptr->left = insert_recursive(ptr->left, temp);
    }
    else if(ptr->key < temp->key){
        ptr->right = insert_recursive(ptr->right, temp);
    }
}

void insert(tree_t *ptr, int key){
    node_t *temp;
    temp = malloc(sizeof(node_t));
    temp->key = key;
    temp->left = temp->right = NULL;
    ptr->root = insert_recursive(ptr->root,temp);
}

static node_t *inorder_successor(node_t *root){
    node_t *temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

static node_t * delete_recursive(node_t *root, int key){

    if(root == NULL) return root;
    else if(key < root->key){
        root->left = delete_recursive(root->left,key);
    }
    else if(key > root->key){
        root->right = delete_recursive(root->right, key); 
    }
    else{
        //key match scenario
        if(root->left == NULL && root->right == NULL){ //leaf
            free(root); return NULL;
        }
        else if(root->left == NULL){ //no left subtree
            node_t *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){//no right subtree
            node_t *temp = root->left;
            free(root); return temp;
        }
        else{ //has both left and right subtrees -> find inorder successor and replace. 
            node_t * temp = inorder_successor(root);
            root->key = temp->key;
            root->right = delete_recursive(root->right, temp->key);
        }
    }



}

void delete_key(tree_t *ptr, int key){
    ptr->root = delete_recursive(ptr->root, key);
}
