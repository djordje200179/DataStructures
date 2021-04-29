#include "pch.h"
#include <stdlib.h>

PriorityQueue* pq_init() {
	return ll_init_list();
}

PriorityQueueNode* pq_init_node(PQ_DATA_TYPE data, int priority) {
	PriorityQueueNode* new_node = (PriorityQueueNode*)malloc(sizeof(PriorityQueueNode));

	if(new_node) {
		new_node->data = data;
		new_node->priority = priority;
	}

	return new_node;
}

void pq_push(PriorityQueue* queue, PQ_DATA_TYPE data, int priority) {
	PriorityQueueNode* queue_node = pq_init_node(data, priority);

	LinkedListNode* list_node = queue->head;
	if(!list_node)
		ll_add_head(queue, queue_node);
	else {
		while(list_node->next && ((PriorityQueueNode*)list_node->next)->priority < priority)
			list_node = list_node->next;

		ll_add_after(queue, list_node, queue_node);
	}
}

PriorityQueueNode* pq_peek(PriorityQueue* queue) {
	LL_DATA_TYPE data = queue->head->data;
	PriorityQueueNode* node = (PriorityQueueNode*)data;
	return node;
}

PriorityQueueNode* pq_pop(PriorityQueue* queue) {
	PriorityQueueNode* data = pq_peek(queue);
	ll_remove_head(queue);
	return data;
}

bool pq_is_empty(PriorityQueue* queue) {
	return ll_is_empty(queue);
}

void pq_clean(PriorityQueue* queue) {
	ll_clean(queue);
}

void pq_dispose(PriorityQueue* queue) {
	ll_dispose(queue);
}