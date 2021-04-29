#include "linked_list.h"
#include <stdio.h>

void print_list_elem(void* data, unsigned long index); 

void ll_test() {
	const int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

	LinkedList* list = ll_init_list();
	for(int i = 0; i < 16; i++)
		ll_add_tail(list, &data[i % 8]);

	ll_remove_at(list, 4);
	ll_remove_head(list);
	ll_add_head(list, &data[4]);
	ll_add_at(list, 4, &data[0]);

	printf("Doubly linked list:\n");
	printf("--head--\n");
	ll_iter_data_index(list, print_list_elem);
	printf("---tail---\n");
	printf("\n");

	ll_dispose(list);
}