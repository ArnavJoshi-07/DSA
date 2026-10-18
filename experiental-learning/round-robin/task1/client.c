#include <stdio.h>
#include "dll.h"

int main()
{
    dll_t list;
    int choice, key1, key2;
    init_dll(&list);

    do {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert after a value\n");
        printf("4. Insert before current\n5. Delete from beginning\n6. Delete from end\n");
        printf("7. Delete a value\n8. Delete current\n9. Move to next\n10. Move to previous\n");
        printf("11. Display forward\n12. Display backward\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &key1);
            insert_begin(&list, key1);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &key1);
            insert_end(&list, key1);
            break;
        case 3:
            printf("Enter existing value and new value: ");
            scanf("%d %d", &key1, &key2);
            insert_after(&list, key1, key2);
            break;
        case 4:
            printf("Enter value: ");
            scanf("%d", &key1);
            insert_before_cur(&list, key1);
            break;
        case 5:
            delete_begin(&list);
            break;
        case 6:
            delete_end(&list);
            break;
        case 7:
            printf("Enter value: ");
            scanf("%d", &key1);
            delete_value(&list, key1);
            break;
        case 8:
            delete_cur(&list);
            break;
        case 9:
            move_next(&list);
            break;
        case 10:
            move_prev(&list);
            break;
        case 11:
            disp_forward(&list);
            break;
        case 12:
            disp_backward(&list);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 0);

    deinit_dll(&list);
    return 0;
}
