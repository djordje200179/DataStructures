#include "pch.h"
#include <stdlib.h>

static PriorityQueueNode* get_pq_node(LinkedListNode* list_node) {
	LL_DATA_TYPE data = list_node->data;
	return (PriorityQueueNode*)data;
}

PriorityQueue* pq_init(Priority priority) {
	PriorityQueue* new_node = (PriorityQueue*)malloc(sizeof(PriorityQueue));

	if(new_node) {
		new_node->list = ll_init();
		new_node->priority = priority;
	}

	return new_node;
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

	LinkedListNode* list_node = queue->list->head;
	if(!list_node ||
	   (queue->priority == SMALLER_FIRST && priority < get_pq_node(list_node)->priority) ||
	   (queue->priority == BIGGER_FIRST && priority > get_pq_node(list_node)->priority))
		ll_add_head(queue->list, queue_node);
	else {
		while(list_node->next && (
			(queue->priority == SMALLER_FIRST && priority > get_pq_node(list_node->next)->priority) ||
			(queue->priority == BIGGER_FIRST && priority < get_pq_node(list_node->next)->priority))
			)
			list_node = list_node->next;

		ll_add_after(queue->list, list_node, queue_node);
	}
}

PriorityQueueNode* pq_peek(PriorityQueue* queue) {
	return get_pq_node(queue->list->head);
}

PriorityQueueNode* pq_pop(PriorityQueue* queue) {
	PriorityQueueNode* data = pq_peek(queue);
	ll_remove_head(queue->list);
	return data;
}

bool pq_is_empty(PriorityQueue* queue) {
	return ll_is_empty(queue->list);
}

void pq_clean(PriorityQueue* queue) {
	ll_clean(queue->list);
}

void pq_dispose(PriorityQueue* queue) {
	ll_dispose(queue->list);
	free(queue);
}