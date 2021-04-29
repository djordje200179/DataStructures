#ifndef QUEUE
#define QUEUE

#include "linked_list.h"
#include <stdbool.h>

typedef void* QUEUE_DATA_TYPE;

typedef LinkedList Queue;

Queue* q_init();

void q_push(Queue* queue, QUEUE_DATA_TYPE data);
QUEUE_DATA_TYPE q_peek(Queue* queue);
QUEUE_DATA_TYPE q_pop(Queue* queue);

bool q_is_empty(Queue* queue);

void q_clean(Queue* queue);
void q_dispose(Queue* queue);

#endif //QUEUE