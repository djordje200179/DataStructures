#ifndef QUEUE
#define QUEUE

#include "single_linked_list.h"

typedef void* QUEUE_DATA_TYPE;

typedef SingleLinkedList Queue;

Queue* q_init();
void q_push(Queue* queue, QUEUE_DATA_TYPE data);
QUEUE_DATA_TYPE q_peek(Queue* queue);
QUEUE_DATA_TYPE q_pop(Queue* queue);

#endif //QUEUE