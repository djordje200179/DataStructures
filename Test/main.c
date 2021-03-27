#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"
#include "single_linked_list.h"

void print_integer(void* data, unsigned long index) {
	int number = *(int*)(data);
	printf("list[%d]: %d\n", index, number);
}

void dll_test() {
	int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

	DoubleLinkedList* list = dll_init_list();
	for(int i = 0; i < 10; i++)
		dll_add_tail(list, &data[i % 8]);

	dll_remove_at(list, 4);
	dll_remove_head(list);
	dll_add_head(list, &data[4]);
	dll_add_at(list, 4, &data[0]);

	printf("Double linked list:\n");
	printf("--head--\n");
	dll_iter_data_index(list, print_integer);
	printf("---tail---\n");
	printf("\n");

	dll_clean(list);
	free(list);
}

void sll_test() {
	int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

	SingleLinkedList* list = sll_init_list();
	for(int i = 0; i < 10; i++)
		sll_add_tail(list, &data[i % 8]);

	sll_remove_at(list, 4);
	sll_remove_head(list);
	sll_add_head(list, &data[4]);
	sll_add_at(list, 4, &data[0]);

	printf("Single linked list:\n");
	printf("--head--\n");
	sll_iter_data_index(list, print_integer);
	printf("---tail---\n");
	printf("\n");

	sll_clean(list);
	free(list);
}

int main() {
	dll_test();
	sll_test();

	return 0;
}