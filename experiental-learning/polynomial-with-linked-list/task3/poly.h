
#ifndef POLY_H
#define POLY_H
#include "term.h"
struct node
{
	term_t term;
	struct node *next;
};
typedef struct node node_t;


struct list
{
	node_t *head_;
};

typedef struct list poly_t;
void init_list(poly_t*);
void insert_list(poly_t*, int coeff, int expo);
void disp_list(poly_t*);
void free_list(poly_t*);
int eval_poly(poly_t*, int);
void copy_list(poly_t*, poly_t*);
#endif

