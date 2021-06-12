#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include "linked_list.h"
#include <stdbool.h>

typedef void* PQ_DATA_TYPE;

typedef enum Priority {
	SMALLER_FIRST,
	BIGGER_FIRST
} Priority;

typedef struct PriorityQueueNode {
	PQ_DATA_TYPE data;

	int priority;
} PriorityQueueNode;

typedef struct PriorityQueue {
	LinkedList* list;

	Priority priority;
} PriorityQueue;

PriorityQueue* pq_init(const Priority priority);
PriorityQueueNode* pq_init_node(const PQ_DATA_TYPE data, const int priority);

void pq_push(PriorityQueue* queue, const PQ_DATA_TYPE data, const int priority);
PriorityQueueNode* pq_peek(const PriorityQueue* queue);
PriorityQueueNode* pq_pop(PriorityQueue* queue);

bool pq_is_empty(const PriorityQueue* queue);

void pq_clean(PriorityQueue* queue);
void pq_dispose(PriorityQueue* queue);

#endif // PRIORITY_QUEUE