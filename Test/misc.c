#include <stdio.h>
#include <stdlib.h>
#include "misc.h"

void print_int_index(void* pointer, unsigned long index) {
	int data = ptr_to_int(pointer);

	printf("%lu: %d\n", index, data);
}

void print_char_index(void* pointer, unsigned long index) {
	char data = ptr_to_char(pointer);

	printf("%lu: %c\n", index, data);
}

void print_int(void* pointer) {
	int data = ptr_to_int(pointer);

	printf("%d", data);
}

void print_char(void* pointer) {
	char data = ptr_to_char(pointer);

	printf("%c", data);
}

void* int_to_ptr(int data) {
	int* pointer = malloc(sizeof(int));

	*pointer = data;

	return pointer;
}

void* char_to_ptr(char data) {
	char* pointer = malloc(sizeof(char));

	*pointer = data;

	return pointer;
}

int ptr_to_int(void* pointer) {
	return *(int*)pointer;
}

char ptr_to_char(void* pointer) {
	return *(char*)pointer;
}

int ptr_to_int_free(void* pointer) {
	int data = *(int*)pointer;

	free(pointer);

	return data;
}

char ptr_to_char_free(void* pointer) {
	char data = *(char*)pointer;

	free(pointer);

	return data;
}

