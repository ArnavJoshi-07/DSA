#include <stdio.h>
#include "dll.h"

#define INSERT_BEGIN 1
#define INSERT_END   2
#define DELETE_BEGIN 3
#define DELETE_END   4
#define DELETE_VAL   5
#define DISP_FWD     6
#define DISP_BWD     7
#define EXIT         8

void menu(){
    printf("\n--- Doubly Linked List ---\n");
    printf("%d. Insert at beginning\n", INSERT_BEGIN);
    printf("%d. Insert at end\n", INSERT_END);
    printf("%d. Delete from beginning\n", DELETE_BEGIN);
    printf("%d. Delete from end\n", DELETE_END);
    printf("%d. Delete by value\n", DELETE_VAL);
    printf("%d. Display forward\n", DISP_FWD);
    printf("%d. Display backward\n", DISP_BWD);
    printf("%d. Exit\n", EXIT);
    printf("Enter choice: ");
}

int main(){
    dll_t ptr;
    init_list(&ptr);

    printf("Enter no of nodes to enter: ");
    int n;
    scanf("%d",&n);
    for(int i = 0; i<n; i++){
        printf("Enter value for node %d : ",i+1);
        int k;
        scanf("%d",&k);
        insert_end(&ptr,k);
    }

    int choice, key;
    do{
        menu();
        if(scanf("%d",&choice) != 1) break;

        switch(choice){
            case INSERT_BEGIN:
                printf("Enter value to insert in beginning : ");
                scanf("%d",&key);
                insert_begin(&ptr,key);
                break;

            case INSERT_END:
                printf("Enter value to insert at end : ");
                scanf("%d",&key);
                insert_end(&ptr,key);
                break;

            case DELETE_BEGIN:
                delete_begin(&ptr);
                break;

            case DELETE_END:
                delete_end(&ptr);
                break;

            case DELETE_VAL:
                printf("Enter value to delete : ");
                scanf("%d",&key);
                delete_val(&ptr,key);
                break;

            case DISP_FWD:
                disp_fwd(&ptr);
                printf("\n");
                break;

            case DISP_BWD:
                disp_bwd(&ptr);
                printf("\n");
                break;

            case EXIT:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }while(choice != EXIT);

    return 0;
}
