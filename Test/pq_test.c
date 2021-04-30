#include "priority_queue.h"
#include "misc.h"
#include <stdio.h>

void pq_test() {
	const char data[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
	const int priorities[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

	PriorityQueue* queue = pq_init(SMALLER_FIRST);
	pq_push(queue, &data[4], priorities[4]);
	pq_push(queue, &data[2], priorities[2]);
	pq_push(queue, &data[7], priorities[7]);
	pq_push(queue, &data[0], priorities[0]);
	pq_push(queue, &data[2], priorities[2]);

	PriorityQueueNode* first = pq_pop(queue);
	PriorityQueueNode* second = pq_pop(queue);
	printf("Priority queue:\n");
	printf("-first: ");
	print_char_index(first->data, first->priority);
	printf("-second: ");
	print_char_index(second->data, second->priority);
	printf("\n");

	pq_dispose(queue);
}