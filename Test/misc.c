#include <stdio.h>

void print_list_elem(void* data, unsigned long index) {
	int number = *(int*)(data);
	printf("list[%d]: %d\n", index, number);
}

void print_char(void* data) {
	char character = *(char*)(data);
	printf("%c", character);
}