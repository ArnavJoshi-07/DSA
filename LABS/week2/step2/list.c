#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "rect.h"

void init_list(mylist_t *ptr_list)
{
    ptr_list->head_ = NULL;
}

// 1. empty list
// 2. insert in the middle
// 3. insert in the beginning
// 4. insert at the end
void insert_list(mylist_t *ptr_list, float length, float breadth)
{
    // create the node
    node_t *temp = (node_t *)malloc(sizeof(node_t));
    set_rect(&temp->rect_, length, breadth);
    temp->next_ = NULL;

    // 1. empty list
    if (ptr_list->head_ == NULL)
    {
        ptr_list->head_ = temp;
        temp->next_ = NULL;
    }
    else
    {
        // traverse, ordered ascending by area (using compare_rect)
        node_t *prev = NULL;
        node_t *pres = ptr_list->head_;
        while (pres != NULL && compare_rect(&pres->rect_, &temp->rect_))
        {
            prev = pres;
            pres = pres->next_;
        }
        if (prev == NULL) // insert in the beginning
        {
            temp->next_ = pres;
            ptr_list->head_ = temp;
        }
        else // middle or end
        {
            temp->next_ = pres;
            prev->next_ = temp;
        }
    }
}

void disp_list(mylist_t *ptr_list)
{
    printf("Display:\n");
    node_t *q = ptr_list->head_;
    int i = 1;
    while (q != NULL)
    {
        printf("Site %d -> ", i++);
        display_rect(&q->rect_);
        q = q->next_;
    }
}

void free_list(mylist_t *ptr_list)
{
    node_t *q = ptr_list->head_;
    node_t *r;
    while (q != NULL)
    {
        r = q->next_;
        free(q);
        q = r;
    }
    ptr_list->head_ = NULL;
    printf("\nThe list is freed\n");
}

/* Additional Problem 1*/
float total_value_list(mylist_t *ptr_list, float unit_value)
{
    float total_area = 0.0f;
    node_t *q = ptr_list->head_;
    while (q != NULL)
    {
        total_area += area_rect(&q->rect_);
        q = q->next_;
    }
    return total_area * unit_value;
}

/* Additional Problem 2*/
node_t *highest_length_site(mylist_t *ptr_list)
{
    if (ptr_list->head_ == NULL)
        return NULL;

    node_t *best = ptr_list->head_;
    node_t *q = ptr_list->head_->next_;
    while (q != NULL)
    {
        if (q->rect_.length > best->rect_.length)
            best = q;
        q = q->next_;
    }
    return best;
}

/* Additional Problem 3*/
node_t *least_breadth_site(mylist_t *ptr_list)
{
    if (ptr_list->head_ == NULL)
        return NULL;

    node_t *best = ptr_list->head_;
    node_t *q = ptr_list->head_->next_;
    while (q != NULL)
    {
        if (q->rect_.breadth < best->rect_.breadth)
            best = q;
        q = q->next_;
    }
    return best;
}