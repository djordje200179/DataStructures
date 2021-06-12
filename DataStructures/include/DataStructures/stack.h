#ifndef STACK
#define STACK

#include "linked_list.h"
#include <stdbool.h>

typedef void* STACK_DATA_TYPE;

typedef LinkedList Stack;

Stack* s_init();

void s_push(Stack* stack, STACK_DATA_TYPE data);
STACK_DATA_TYPE s_peek(Stack* stack);
STACK_DATA_TYPE s_pop(Stack* stack);

bool s_is_empty(Stack* stack);

void s_clean(Stack* stack);
void s_dispose(Stack* stack);

#endif // STACK