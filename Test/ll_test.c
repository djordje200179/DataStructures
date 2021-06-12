#include <DataStructures/linked_list.h>
#include "misc.h"
#include <stdio.h>

void ll_test() {
	set_text_color(GREEN_COLOR);
	printf("Linked list:\n");
	set_text_color(NO_COLOR);

	LinkedList* list = ll_init();

	for(int i = 0; i < 16; i++)
		ll_add_tail(list, int_to_ptr(i % 8));

	ll_remove_at(list, 4);
	ll_remove_head(list);
	ll_add_head(list, int_to_ptr(4));
	ll_add_at(list, 4, int_to_ptr(0));

	printf("--head--\n");
	ll_iter_data_index(list, print_int_index);
	printf("---tail---\n");
	printf("\n");

	ll_dispose(list);
}