#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include "linked_list.h"
#include <stdbool.h>

typedef void* PQ_DATA_TYPE;

typedef struct PriorityQueueNode {
	PQ_DATA_TYPE data;

	int priority;
} PriorityQueueNode;

typedef LinkedList PriorityQueue;

PriorityQueue* pq_init();
PriorityQueueNode* pq_init_node(PQ_DATA_TYPE data, int priority);

void pq_push(PriorityQueue* queue, PQ_DATA_TYPE data, int priority);
PriorityQueueNode* pq_peek(PriorityQueue* queue);
PriorityQueueNode* pq_pop(PriorityQueue* queue);

bool pq_is_empty(PriorityQueue* queue);

void pq_clean(PriorityQueue* queue);
void pq_dispose(PriorityQueue* queue);

#endif //PRIORITY_QUEUE