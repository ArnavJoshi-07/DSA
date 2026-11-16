#include"queue.h"
#include<stdio.h>

int main() {
	int opt;
	queue q = {};
	q_init(&q);
	do {
		printf("Enter choice: (1 to enqueue, 2 to dequeue, 3 to print, 0 to exit)\n");
		scanf("%d", &opt);
		switch(opt) {
			case 1:
				printf("Enter key :");
				int k;
				scanf("%d", &k);
				enqueue(&q,k);
				break;
			case 2:
				dequeue(&q);
				break;
			case 3:
				q_print(&q);
				break;
		}
	}while(opt);
	q_deinit(&q);
}
