#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

/* base is double so that non-integral limits evaluate correctly; negative
 * exponents are supported because the input may contain them */
static double power(double base, int exp)
{
    double result = 1.0;
    int n = exp;
    if(n < 0)
        n = -n;
    for(int i = 0; i<n; i++)
        result = result * base;
    if(exp < 0)
        result = 1.0 / result;
    return result;
}

void init_poly(poly_t *ptr_poly)
{
    ptr_poly->head_ = NULL;
}

void insert_poly(poly_t *ptr_poly, double coeff, int expo)
{
    if(coeff == 0)
        return;

    node_t *temp = malloc(sizeof(node_t));
    set_term(&temp->term, coeff, expo);
    temp->next = NULL;

    if(ptr_poly->head_ == NULL){
        ptr_poly->head_ = temp;
        return;
    }

    node_t *prev = NULL;
    node_t *pres = ptr_poly->head_;
    while(pres!=NULL && compare_expo(&pres->term, &temp->term)>0){
        prev = pres;
        pres = pres->next;
    }

    if(pres!=NULL && compare_expo(&pres->term, &temp->term)==0){
        set_term(&pres->term, pres->term.coeff + coeff, pres->term.expo);
        free(temp);
        if(pres->term.coeff == 0){
            if(prev==NULL)
                ptr_poly->head_ = pres->next;
            else
                prev->next = pres->next;
            free(pres);
        }
        return;
    }

    temp->next = pres;
    if(prev==NULL)
        ptr_poly->head_ = temp;
    else
        prev->next = temp;
}

poly_t create_poly(void)
{
    poly_t poly;
    init_poly(&poly);

    int n;
    printf("Number of terms: ");
    if(scanf("%d", &n)!=1 || n<0){
        printf("Invalid number of terms.\n");
        return poly;
    }

    double coeff;
    int expo;
    for(int i = 0; i<n; i++){
        printf("Coefficient Exponent: ");
        if(scanf("%lf %d", &coeff, &expo)!=2){
            printf("Invalid term.\n");
            break;
        }
        insert_poly(&poly, coeff, expo);
    }
    return poly;
}

void display_poly(poly_t poly)
{
    node_t *q = poly.head_;
    if(q==NULL){
        printf("0\n");
        return;
    }
    while(q!=NULL){
        print_term(&q->term, q==poly.head_);
        q = q->next;
    }
    printf("\n");
}

void add_poly(poly_t poly1, poly_t poly2, poly_t *sum)
{
    init_poly(sum);
    node_t *q = poly1.head_;
    node_t *p = poly2.head_;

    while(q!=NULL && p!=NULL){
        int cmp = compare_expo(&q->term, &p->term);
        if(cmp>0){
            insert_poly(sum, q->term.coeff, q->term.expo);
            q = q->next;
        }
        else if(cmp<0){
            insert_poly(sum, p->term.coeff, p->term.expo);
            p = p->next;
        }
        else{
            insert_poly(sum, q->term.coeff + p->term.coeff, q->term.expo);
            q = q->next;
            p = p->next;
        }
    }
    while(q!=NULL){
        insert_poly(sum, q->term.coeff, q->term.expo);
        q = q->next;
    }
    while(p!=NULL){
        insert_poly(sum, p->term.coeff, p->term.expo);
        p = p->next;
    }
}

double eval_poly(poly_t poly, double x)
{
    double res = 0.0;
    node_t *q = poly.head_;
    while(q!=NULL){
        res = res + q->term.coeff * power(x, q->term.expo);
        q = q->next;
    }
    return res;
}

/* poly is passed by value, but that copies only the head pointer, so the
 * nodes are shared with the caller: read q->term, never write through it */
poly_t integrate_poly(poly_t poly)
{
    poly_t result;
    init_poly(&result);

    node_t *q = poly.head_;
    term_t t;
    while(q!=NULL){
        integrate_term(&q->term, &t);
        insert_poly(&result, t.coeff, t.expo);
        q = q->next;
    }
    return result;
}

void destroy_poly(poly_t *poly)
{
    node_t *q = poly->head_;
    node_t *r;
    while(q!=NULL){
        r = q->next;
        free(q);
        q = r;
    }
    poly->head_ = NULL;
}
