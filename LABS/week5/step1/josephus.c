#include <stddef.h>
#include "josephus.h"

node_t *remove_kth(clist_t *ptr_clist, node_t **ptr_cur, int k)
{
    node_t *cur = *ptr_cur;
    int i;

    if(cur == NULL || k < 1)
        return NULL;

    /* k-1 hops leave cur just before the k-th person, so k = 1 needs no hop */
    for(i = 1; i < k; i++)
        cur = cur->next_;

    *ptr_cur = cur;
    return remove_after(ptr_clist, cur);
}
