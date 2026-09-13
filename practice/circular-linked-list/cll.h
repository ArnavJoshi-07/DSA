#ifndef clist_H
#define clist_H
struct node
{
	int key;
	struct node *next;
};
typedef struct node node_t;


struct clist
{
	node_t *head;
};
typedef struct clist clist_t;

void init_clist(clist_t*);
void insert_begin(clist_t* ptr_clist, int key);
void insert_end(clist_t* ptr_clist, int data);

void disp_list(clist_t* ptr_clist);
void free_clist(clist_t*);

#endif