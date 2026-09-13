#include <stdio.h>
#include "term.h"
void set_term(term_t *ptr_term, int coeff, int expo){
    ptr_term->coeff = coeff;
    ptr_term->expo = expo;
}
void disp_term(term_t *ptr_term){
    printf("%dx^%d ",ptr_term->coeff, ptr_term->expo);
}
int compare_expo(term_t *left, term_t *right){
        return left->expo - right->expo;
}