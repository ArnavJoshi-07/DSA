#ifndef LIST_H
#define LIST_H

#include "rect.h"

struct node
{
    rect_t       rect_;
    struct node *next_;
};
typedef struct node node_t;

struct mylist
{
    node_t *head_;
};
typedef struct mylist mylist_t;

void init_list(mylist_t *ptr_list);
void insert_list(mylist_t *ptr_list, float length, float breadth);
void disp_list(mylist_t *ptr_list);
void free_list(mylist_t *ptr_list);

/* Aditional problmes */
float total_value_list(mylist_t *ptr_list, float unit_value);
node_t *highest_length_site(mylist_t *ptr_list);
node_t *least_breadth_site(mylist_t *ptr_list);

#endif