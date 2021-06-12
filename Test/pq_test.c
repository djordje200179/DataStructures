#include <DataStructures/priority_queue.h>
#include "misc.h"
#include <stdio.h>

void pq_test() {
	set_text_color(GREEN_COLOR);
	printf("Priority queue:\n");
	set_text_color(NO_COLOR);

	PriorityQueue* queue = pq_init(SMALLER_FIRST);

	pq_push(queue, char_to_ptr('E'), 4);
	pq_push(queue, char_to_ptr('C'), 2);
	pq_push(queue, char_to_ptr('H'), 7);
	pq_push(queue, char_to_ptr('A'), 0);
	pq_push(queue, char_to_ptr('D'), 2);

	PriorityQueueNode* first = pq_pop(queue);
	PriorityQueueNode* second = pq_pop(queue);

	printf("-first: ");
	print_char_index(first->data, first->priority);
	printf("-second: ");
	print_char_index(second->data, second->priority);
	printf("\n");

	pq_dispose(queue);
}