#ifndef JOSEPHUS_H
#define JOSEPHUS_H

#include "clist.h"

/* Counts k people from *ptr_cur->next_ and removes the k-th; caller frees it */
node_t *remove_kth(clist_t *ptr_clist, node_t **ptr_cur, int k);

#endif
