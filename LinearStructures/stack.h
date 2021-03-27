#ifndef STACK
#define STACK

#include "single_linked_list.h"

typedef void* STACK_DATA_TYPE;

typedef SingleLinkedList Stack;

Stack* s_init();
void s_push(Stack* stack, STACK_DATA_TYPE data);
STACK_DATA_TYPE s_peek(Stack* queue);
STACK_DATA_TYPE s_pop(Stack* queue);

#endif //STACK