#include <stdio.h>
#include "dll.h"

static void read_job(job_t *ptr_job)
{
    int id;
    char name[NAME_LEN];
    printf("Enter job id and name: ");
    scanf("%d %19s", &id, name);
    set_job(ptr_job, id, name);
}

int main()
{
    dll_t list;
    job_t job;
    int choice, id;
    init_dll(&list);

    do {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert after a job\n");
        printf("4. Insert before current\n5. Delete from beginning\n6. Delete from end\n");
        printf("7. Delete a job\n8. Delete current\n9. Move to next\n10. Move to previous\n");
        printf("11. Display forward\n12. Display backward\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
        case 1:
            read_job(&job);
            insert_begin(&list, job);
            break;
        case 2:
            read_job(&job);
            insert_end(&list, job);
            break;
        case 3:
            printf("Enter id of existing job: ");
            scanf("%d", &id);
            read_job(&job);
            insert_after(&list, id, job);
            break;
        case 4:
            read_job(&job);
            insert_before_cur(&list, job);
            break;
        case 5:
            delete_begin(&list);
            break;
        case 6:
            delete_end(&list);
            break;
        case 7:
            printf("Enter job id: ");
            scanf("%d", &id);
            delete_value(&list, id);
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
