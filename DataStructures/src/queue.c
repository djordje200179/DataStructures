#include "pch.h"

Queue* q_init() {
	return ll_init();
}

void q_push(Queue* queue, const QUEUE_DATA_TYPE data) {
	ll_add_tail(queue, data);
}

QUEUE_DATA_TYPE q_peek(const Queue* queue) {
	return queue->head->data;
}

QUEUE_DATA_TYPE q_pop(Queue* queue) {
	QUEUE_DATA_TYPE data = q_peek(queue);
	ll_remove_head(queue);
	return data;
}

bool q_is_empty(const Queue* queue) {
	return ll_is_empty(queue);
}

void q_clean(Queue* queue) {
	ll_clean(queue);
}

void q_dispose(Queue* queue) {
	ll_dispose(queue);
}