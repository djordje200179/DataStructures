#include <DataStructures/queue.h>
#include "misc.h"
#include <stdio.h>

void q_test() {
	set_text_color(GREEN_COLOR);
	printf("Queue:\n");
	set_text_color(NO_COLOR);

	Queue* queue = q_init();

	q_push(queue, int_to_ptr(1));
	q_push(queue, int_to_ptr(2));
	q_push(queue, int_to_ptr(3));
	q_push(queue, int_to_ptr(4));

	printf("--peek--\n");
	printf("%d\n", ptr_to_int(q_peek(queue)));
	printf("--pop--\n");
	printf("%d\n", ptr_to_int_free(q_pop(queue)));
	printf("%d\n", ptr_to_int_free(q_pop(queue)));
	printf("\n");

	q_dispose(queue);
}