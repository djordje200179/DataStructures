#include "pch.h"

PriorityQueue* pq_init() {
	return ll_init_list();
}

// TODO: Implement adding element to priority queue
void pq_push(PriorityQueue* queue, PQ_DATA_TYPE data) {
	
}

PQ_DATA_TYPE pq_peek(PriorityQueue* queue) {
	return queue->head->data;
}

PQ_DATA_TYPE pq_pop(PriorityQueue* queue) {
	PQ_DATA_TYPE data = pq_peek(queue);
	ll_remove_head(queue);
	return data;
}

bool pq_is_empty(PriorityQueue* queue) {
	return queue->size == 0;
}

void pq_clean(PriorityQueue* queue) {
	ll_clean(queue);
}

void pq_dispose(PriorityQueue* queue) {
	ll_dispose(queue);
}