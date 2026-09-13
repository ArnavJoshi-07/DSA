#include "poly.h"
#include <stdio.h>
#include <stdlib.h>
int power(int base, int exp)
{
    int result = 1;
    for(int i = 0; i < exp; ++i)
        result *= base;
    return result;
}

void init_list(poly_t* ptr_poly){
    ptr_poly->head_ = NULL;
}
void insert_list(poly_t *ptr_poly, int coeff, int expo){
    node_t *temp = malloc(sizeof(node_t));
    set_term(&temp->term, coeff, expo);
    temp->next = NULL;
    if(ptr_poly->head_ == NULL){
        ptr_poly->head_ = temp;   
    }
    else{
        node_t *prev = NULL;
        node_t *pres = ptr_poly->head_;
        while(pres!=NULL && compare_expo(&pres->term, &temp->term)>0){
            prev = pres;
            pres = pres->next;
        }
        if(pres!=NULL && compare_expo(&pres->term, &temp->term)==0){
            set_term(&pres->term, pres->term.coeff + coeff, pres->term.expo);
            free(temp);
            return;
        }
        if(prev==NULL){
            temp->next = pres;
            ptr_poly->head_ = temp;
        }
        else{
            temp->next = pres;
            prev->next = temp;
        }
    }

}
void disp_list(poly_t *ptr_poly){
    node_t *q = ptr_poly->head_;
    while(q!=NULL){
        disp_term(&q->term);
        q = q->next;
    }
}
void free_list(poly_t *ptr_poly){
    node_t *q = ptr_poly->head_;
    node_t *r;
    while(q!=NULL){
        r = q->next;
        free(q);
        q = r;
    }
    ptr_poly->head_ = NULL;
    printf("The polynomial is freed. \n");
}
int eval_poly(poly_t* ptr_poly, int x){
    node_t *temp = ptr_poly->head_;
    
    int res = 0;
    while(temp!=NULL){
        res = res + temp->term.coeff * power(x,temp->term.expo);
        temp = temp->next;
    }
    return res;
}
void copy_list(poly_t* src, poly_t* dest){
    node_t *q = src->head_;
    while(q!=NULL){
        insert_list(dest, q->term.coeff, q->term.expo);
        q = q->next;
    }
}
void diff_list(poly_t * src, poly_t *dest){
    node_t *q = src->head_;
    while(q!=NULL){
        if(q->term.expo != 0){
            insert_list(dest,q->term.coeff * q->term.expo, q->term.expo -1);
        }
        q=  q->next;
    }
}