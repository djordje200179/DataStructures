#include <stdio.h>

void print_int_index(void* data, unsigned long index) {
	int converted_data = *(int*)(data);
	printf("%d: %d\n", index, converted_data);
}

void print_char_index(void* data, unsigned long index) {
	char converted_data = *(char*)(data);
	printf("%d: %c\n", index, converted_data);
}

void print_int(void* data) {
	int converted_data = *(int*)(data);
	printf("%d", converted_data);
}

void print_char(void* data) {
	char converted_data = *(char*)(data);
	printf("%c", converted_data);
}