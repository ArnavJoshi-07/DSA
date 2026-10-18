#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "josephus.h"

static void flush_line(void)
{
    int ch;

    while((ch = getchar()) != '\n' && ch != EOF)
        ;
}

/* gets() is not available here, so read the line and trim the newline fgets keeps */
static void read_name(char *buf, int size)
{
    int len;

    if(fgets(buf, size, stdin) == NULL){
        buf[0] = '\0';
        return;
    }

    len = strcspn(buf, "\n");
    if(buf[len] == '\n')
        buf[len] = '\0';
    else
        flush_line();
}

int main(void)
{
    clist_t circle;
    node_t *cur, *out;
    char name[NAME_LEN];
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
    flush_line();

    init_clist(&circle);
    for(i = 1; i <= n; i++){
        printf("Name of person #%d: ", i);
        read_name(name, NAME_LEN);
        insert_end(&circle, i, name);
    }

    printf("\n");
    disp_list(&circle);

    /* counting starts at cur->next_, so cur has to be the node before person 1 */
    cur = last_node(&circle);

    printf("\nElimination order:\n");
    for(i = 1; i <= n - 1; i++){
        out = remove_kth(&circle, &cur, k);
        printf("  Round %2d: %s (person #%d) executed\n", i, out->name_, out->key_);
        free(out);
    }

    printf("\n");
    disp_list(&circle);
    printf("Survivor -> %s (person #%d)\n", circle.head_->name_, circle.head_->key_);

    free_clist(&circle);
    return 0;
}
