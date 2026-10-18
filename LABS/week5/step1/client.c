#include <stdio.h>
#include <stdlib.h>
#include "josephus.h"

int main(void)
{
    clist_t circle;
    node_t *cur, *out;
    int n, k, i;

    printf("Enter number of people (n): ");
    if(scanf("%d", &n) != 1 || n < 1){
        printf("Invalid number of people.\n");
        return 1;
    }

    printf("Enter the count k [kth element is removed]: ");
    if(scanf("%d", &k) != 1 || k < 1){
        printf("Invalid count.\n");
        return 1;
    }

    init_clist(&circle);
    for(i = 1; i <= n; i++)
        insert_end(&circle, i);

    disp_list(&circle);

    /* counting starts at cur->next_, so cur has to be the node before person 1 */
    cur = last_node(&circle);

    printf("\nElimination order:\n");
    for(i = 1; i <= n - 1; i++){
        out = remove_kth(&circle, &cur, k);
        printf("  Round %2d: person #%d executed\n", i, out->key_);
        free(out);
    }

    printf("\n");
    disp_list(&circle);
    printf("Survivor -> person #%d\n", circle.head_->key_);

    free_clist(&circle);
    return 0;
}
