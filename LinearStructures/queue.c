#include "pch.h"

Queue* q_init() {
	return sll_init_list();
}

void q_push(Queue* queue, QUEUE_DATA_TYPE data) {
	sll_add_tail(queue, data);
}

QUEUE_DATA_TYPE q_peek(Queue* queue) {
	return queue->head->data;
}

QUEUE_DATA_TYPE q_pop(Queue* queue) {
	QUEUE_DATA_TYPE data = q_peek(queue);
	sll_remove_head(queue);
	return data;
}