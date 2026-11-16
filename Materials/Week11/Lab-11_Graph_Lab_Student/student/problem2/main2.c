#include <stdio.h>
#include "graph_2.h"

int main(void)
{
	graph_t g;
	init_graph(&g, 8, 4);
	add_edge(&g, 0, 1);   /* A-B */
	add_edge(&g, 1, 2);   /* B-C */
	add_edge(&g, 3, 4);   /* D-E */
	add_edge(&g, 5, 6);   /* F-G */
	                      /* H is isolated */
	disp(&g);

	int before = connected_components(&g);
	printf("Before: %d groups\n\n", before);

	int added = connect_components(&g);
	printf("Added %d edges\n\n", added);

	int after = connected_components(&g);
	printf("After: %d group\n", after);

	deinit_graph(&g);
	return 0;
}
