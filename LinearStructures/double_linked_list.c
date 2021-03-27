#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

DoubleLinkedList* dll_init_list() {
	DoubleLinkedList* new_list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));

	if(new_list) {
		new_list->head = NULL;
		new_list->tail = NULL;
		new_list->size = 0;
	}

	return new_list;
}

DoubleLinkedListNode* dll_init_node(DLL_DATA_TYPE data) {
	DoubleLinkedListNode* new_node = (DoubleLinkedListNode*)malloc(sizeof(DoubleLinkedListNode));

	if (new_node) {
		new_node->data = data;
		new_node->prev = NULL;
		new_node->next = NULL;
	}

	return new_node;
}

DoubleLinkedListNode* dll_add_at(DoubleLinkedList* list, unsigned long index, DLL_DATA_TYPE data) {
	if (index == 0)
		return dll_add_head(list, data);
	if(index == list->size - 1)
		return dll_add_tail(list, data);
	else {
		DoubleLinkedListNode* new_node = dll_init_node(data);
		DoubleLinkedListNode* next_node = dll_get_elem(list, index);
		DoubleLinkedListNode* prev_node = next_node->prev;

		prev_node->next = new_node;
		new_node->prev = prev_node;
		new_node->next = next_node;
		next_node->prev = new_node;

		list->size++;

		return new_node;
	}
}

DoubleLinkedListNode* dll_add_after(DoubleLinkedList* list, DoubleLinkedListNode* prev_node, DLL_DATA_TYPE data) {
	DoubleLinkedListNode* next_node = prev_node->next;
	DoubleLinkedListNode* new_node = dll_init_node(data);

	prev_node->next = new_node;
	new_node->prev = prev_node;
	new_node->next = next_node;
	next_node->prev = new_node;

	list->size++;

	return new_node;
}

DoubleLinkedListNode* dll_add_head(DoubleLinkedList* list, DLL_DATA_TYPE data) {
	DoubleLinkedListNode* new_node = dll_init_node(data);

	if(list->head == NULL)
		list->head = list->tail = new_node;
	else {
		DoubleLinkedListNode* second_node = list->head;

		new_node->next = second_node;
		second_node->prev = new_node;
		list->head = new_node;
	}

	list->size++;

	return new_node;
}

DoubleLinkedListNode* dll_add_tail(DoubleLinkedList* list, DLL_DATA_TYPE data) {
	DoubleLinkedListNode* new_node = dll_init_node(data);

	if(list->head == NULL)
		list->head = list->tail = new_node;
	else {
		DoubleLinkedListNode* second_node = list->tail;

		new_node->prev = second_node;
		second_node->next = new_node;
		list->tail = new_node;
	}

	list->size++;

	return new_node;
}

void dll_clean(DoubleLinkedList* list) {
	DoubleLinkedListNode* current_node = list->head;

	while (current_node) {
		DoubleLinkedListNode* next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	list->head = list->tail = NULL;
	list->size = 0;
}

void dll_remove_at(DoubleLinkedList* list, unsigned long index) {
	if(index == 0)
		dll_remove_head(list);
	else if(index == list->size - 1)
		dll_remove_tail(list);
	else {
		DoubleLinkedListNode* node = dll_get_elem(list, index);
		DoubleLinkedListNode* prev_node = node->prev;
		DoubleLinkedListNode* next_node = node->next;

		prev_node->next = next_node;
		next_node->prev = prev_node;

		list->size--;

		free(node);
	}
}

void dll_remove_elem(DoubleLinkedList* list, DoubleLinkedListNode* node) {
	if(node == list->head)
		dll_remove_head(list);
	else if(node == list->tail)
		dll_remove_tail(list);
	else {
		DoubleLinkedListNode* prev_node = node->prev;
		DoubleLinkedListNode* next_node = node->next;

		prev_node->next = next_node;
		next_node->prev = prev_node;

		list->size--;

		free(node);
	}
}

void dll_remove_head(DoubleLinkedList* list) {
	DoubleLinkedListNode* first_node = list->head;
	DoubleLinkedListNode* second_node = first_node->next;
	
	list->head = second_node;
	list->size--;

	if(second_node)
		second_node->prev = NULL;

	free(first_node);
}

void dll_remove_tail(DoubleLinkedList* list) {
	DoubleLinkedListNode* first_node = list->tail;
	DoubleLinkedListNode* second_node = first_node->prev;

	list->tail = second_node;
	list->size--;

	if(second_node)
		second_node->next = NULL;

	free(first_node);
}

DoubleLinkedListNode* dll_get_elem(DoubleLinkedList* list, unsigned long index) {
	DoubleLinkedListNode* current_node = list->head;
	for (unsigned long i = 0; i < index; i++)
		current_node = current_node->next;

	return current_node;
}

DLL_DATA_TYPE dll_get_data(DoubleLinkedList* list, unsigned long index) {
	return dll_get_elem(list, index)->data;
}

void dll_iter_elem(DoubleLinkedList* list, void(*function)(DoubleLinkedListNode*)) {
	for (DoubleLinkedListNode* current_node = list->head; current_node; current_node = current_node->next)
		function(current_node);
}

void dll_iter_elem_index(DoubleLinkedList* list, void (*function)(DoubleLinkedListNode*, unsigned long)) {
	unsigned long i = 0;
	for (DoubleLinkedListNode* current_node = list->head; current_node; current_node = current_node->next, i++)
		function(current_node, i);
}

void dll_iter_data(DoubleLinkedList* list, void(*function)(DLL_DATA_TYPE)) {
	for (DoubleLinkedListNode* current_node = list->head; current_node; current_node = current_node->next)
		function(current_node->data);
}

void dll_iter_data_index(DoubleLinkedList* list, void (*function)(DLL_DATA_TYPE, unsigned long)) {
	unsigned long i = 0;
	for (DoubleLinkedListNode* current_node = list->head; current_node; current_node = current_node->next, i++)
		function(current_node->data, i);
}

void dll_iter_reverse_elem(DoubleLinkedList* list, void(*function)(DoubleLinkedListNode*)) {
	for (DoubleLinkedListNode* current_node = list->tail; current_node; current_node = current_node->prev)
		function(current_node);
}

void dll_iter_reverse_elem_index(DoubleLinkedList* list, void (*function)(DoubleLinkedListNode*, unsigned long)) {
	unsigned long i = list->size - 1;
	for (DoubleLinkedListNode* current_node = list->tail; current_node; current_node = current_node->prev, i--)
		function(current_node, i);
}

void dll_iter_reverse_data(DoubleLinkedList* list, void(*function)(DLL_DATA_TYPE)) {
	for (DoubleLinkedListNode* current_node = list->tail; current_node; current_node = current_node->prev)
		function(current_node->data);
}

void dll_iter_reverse_data_index(DoubleLinkedList* list, void (*function)(DLL_DATA_TYPE, unsigned long)) {
	unsigned long i = list->size - 1;
	for (DoubleLinkedListNode* current_node = list->tail; current_node; current_node = current_node->prev, i--)
		function(current_node->data, i);
}