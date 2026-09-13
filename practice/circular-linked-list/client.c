#include "cll.h"
#include <stdio.h>

int main(void)
{
    clist_t list;

    init_clist(&list);

    printf("Initial list:\n");
    disp_list(&list);

    printf("\nInserting 20 at beginning:\n");
    insert_begin(&list, 20);
    disp_list(&list);

    printf("\nInserting 10 at beginning:\n");
    insert_begin(&list, 10);
    disp_list(&list);

    printf("\nInserting 30 at end:\n");
    insert_end(&list, 30);
    disp_list(&list);

    printf("\nInserting 40 at end:\n");
    insert_end(&list, 40);
    disp_list(&list);

    printf("\nFreeing list...\n");
    free_clist(&list);

    printf("List after freeing:\n");
    disp_list(&list);

    return 0;
}
