#include "pch.h"

Stack* s_init() {
	return sll_init_list();
}

void s_push(Stack* Stack, STACK_DATA_TYPE data) {
	sll_add_head(Stack, data);
}

STACK_DATA_TYPE s_peek(Stack* Stack) {
	return Stack->head->data;
}

STACK_DATA_TYPE s_pop(Stack* Stack) {
	STACK_DATA_TYPE data = s_peek(Stack);
	sll_remove_head(Stack);
	return data;
}
