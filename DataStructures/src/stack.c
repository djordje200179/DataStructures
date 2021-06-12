#include "pch.h"

Stack* s_init() {
	return ll_init();
}

void s_push(Stack* stack, STACK_DATA_TYPE data) {
	ll_add_tail(stack, data);
}

STACK_DATA_TYPE s_peek(Stack* stack) {
	return stack->tail->data;
}

STACK_DATA_TYPE s_pop(Stack* stack) {
	STACK_DATA_TYPE data = s_peek(stack);
	ll_remove_tail(stack);
	return data;
}

bool s_is_empty(Stack* stack) {
	return ll_is_empty(stack);
}

void s_clean(Stack* stack) {
	ll_clean(stack);
}

void s_dispose(Stack* stack) {
	ll_dispose(stack);
}