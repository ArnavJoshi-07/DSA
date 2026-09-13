#include <stdio.h>
#include "rect.h"
#include "list.h"

int main(void)
{
    mylist_t list;
    init_list(&list);

    int n;
    printf("Enter the number of sites : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        float length, breadth;
        printf("Enter length and breadth of site %d : ", i + 1);
        scanf("%f %f", &length, &breadth);
        insert_list(&list, length, breadth);
    }

    printf("\nOrdered list of sites (ascending by area):\n");
    disp_list(&list);

    /* Additional Problem 1: total value of the layout */
    float unit_value;
    printf("\nEnter the value of a unit area : ");
    scanf("%f", &unit_value);
    float total_value = total_value_list(&list, unit_value);
    printf("Total value of the layout : %.2f\n", total_value);

    /* Additional Problem 2: site with highest length */
    node_t *hl = highest_length_site(&list);
    if (hl != NULL)
    {
        printf("\nSite with the highest length -> ");
        display_rect(&hl->rect_);
    }

    /* Additional Problem 3: site with least breadth */
    node_t *lb = least_breadth_site(&list);
    if (lb != NULL)
    {
        printf("\nSite with the least breadth -> ");
        display_rect(&lb->rect_);
    }

    free_list(&list);

    return 0;
}