#include "pch.h"

Queue* q_init() {
	return ll_init_list();
}

void q_push(Queue* queue, QUEUE_DATA_TYPE data) {
	ll_add_tail(queue, data);
}

QUEUE_DATA_TYPE q_peek(Queue* queue) {
	return queue->head->data;
}

QUEUE_DATA_TYPE q_pop(Queue* queue) {
	QUEUE_DATA_TYPE data = q_peek(queue);
	ll_remove_head(queue);
	return data;
}

bool q_is_empty(Queue* queue) {
	return ll_is_empty(queue);
}

void q_clean(Queue* queue) {
	ll_clean(queue);
}

void q_dispose(Queue* queue) {
	ll_dispose(queue);
}