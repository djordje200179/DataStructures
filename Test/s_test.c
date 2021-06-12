#include <DataStructures/stack.h>
#include "misc.h"
#include <stdio.h>

void s_test() {
	set_text_color(GREEN_COLOR);
	printf("Stack:\n");
	set_text_color(NO_COLOR);

	Stack* stack = s_init();

	s_push(stack, int_to_ptr(1));
	s_push(stack, int_to_ptr(2));
	s_push(stack, int_to_ptr(3));
	s_push(stack, int_to_ptr(4));

	printf("--peek--\n");
	printf("%d\n", ptr_to_int(s_peek(stack)));
	printf("--pop--\n");
	printf("%d\n", ptr_to_int_free(s_pop(stack)));
	printf("%d\n", ptr_to_int_free(s_pop(stack)));
	printf("\n");

	s_dispose(stack);
}