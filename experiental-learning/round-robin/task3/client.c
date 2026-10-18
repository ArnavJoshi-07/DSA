#include <stdio.h>
#include "dll.h"

static void read_job(job_t *ptr_job)
{
    int id, time_needed;
    char name[NAME_LEN];
    printf("Enter job id, name and time for completion: ");
    scanf("%d %19s %d", &id, name, &time_needed);
    set_job(ptr_job, id, name, time_needed);
}

int main()
{
    dll_t list;
    job_t job;
    job_t *cur;
    int choice, slice;
    init_dll(&list);

    printf("Enter time slice: ");
    if (scanf("%d", &slice) != 1 || slice <= 0) {
        printf("Invalid time slice\n");
        return 1;
    }

    do {
        printf("\n1. Add job\n2. Process job\n3. Display jobs\n0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
        case 1:
            read_job(&job);
            insert_before_cur(&list, job);
            break;
        case 2:
            cur = get_cur(&list);
            if (cur == NULL) {
                printf("No jobs to process\n");
                break;
            }
            allot_time(cur, slice);
            printf("Processed ");
            disp_job(cur);
            printf("\n");
            if (is_complete(cur)) {
                printf("Job %d completed\n", cur->id_);
                delete_cur(&list);
            } else {
                move_next(&list);
            }
            break;
        case 3:
            disp_forward(&list);
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
