#ifndef TERM_H
#define TERM_H
struct term{
    int coeff;
    int expo;
};
typedef struct term term_t;
void set_term(term_t * ptr_term, int coeff, int expo);
void disp_term(term_t * ptr_term);
int compare_expo(term_t * left, term_t *right);
#endif