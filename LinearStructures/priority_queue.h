#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include "linked_list.h"
#include <stdbool.h>

typedef void* PQ_DATA_TYPE;

typedef LinkedList PriorityQueue;

PriorityQueue* pq_init();

void pq_push(PriorityQueue* queue, PQ_DATA_TYPE data);
PQ_DATA_TYPE pq_peek(PriorityQueue* queue);
PQ_DATA_TYPE pq_pop(PriorityQueue* queue);

bool pq_is_empty(PriorityQueue* queue);

void pq_clean(PriorityQueue* queue);
void pq_dispose(PriorityQueue* queue);

#endif //PRIORITY_QUEUE