#include "pch.h"
#include <stdlib.h>

LinkedList* ll_init() {
	LinkedList* new_list = (LinkedList*)malloc(sizeof(LinkedList));

	if(new_list) {
		new_list->size = 0;

		new_list->head = NULL;
		new_list->tail = NULL;
	}

	return new_list;
}

LinkedListNode* ll_init_node(LL_DATA_TYPE data) {
	LinkedListNode* new_node = (LinkedListNode*)malloc(sizeof(LinkedListNode));

	if(new_node) {
		new_node->data = data;

		new_node->prev = NULL;
		new_node->next = NULL;
	}

	return new_node;
}

LinkedListNode* ll_add_at(LinkedList* list, unsigned long index, LL_DATA_TYPE data) {
	if(index == 0)
		return ll_add_head(list, data);
	else if(index == list->size - 1)
		return ll_add_tail(list, data);
	else {
		LinkedListNode* new_node = ll_init_node(data);
		LinkedListNode* next_node = ll_get_elem(list, index);
		LinkedListNode* prev_node = next_node->prev;

		prev_node->next = new_node;
		new_node->prev = prev_node;
		new_node->next = next_node;
		next_node->prev = new_node;

		list->size++;

		return new_node;
	}
}

LinkedListNode* ll_add_after(LinkedList* list, LinkedListNode* prev_node, LL_DATA_TYPE data) {
	LinkedListNode* next_node = prev_node->next;
	LinkedListNode* new_node = ll_init_node(data);

	if(prev_node == list->tail)
		return ll_add_tail(list, data);
	else {
		prev_node->next = new_node;
		new_node->prev = prev_node;
		new_node->next = next_node;
		next_node->prev = new_node;

		list->size++;

		return new_node;
	}
}

LinkedListNode* ll_add_head(LinkedList* list, LL_DATA_TYPE data) {
	LinkedListNode* new_node = ll_init_node(data);

	if(!list->head)
		list->head = list->tail = new_node;
	else {
		LinkedListNode* second_node = list->head;

		new_node->next = second_node;
		second_node->prev = new_node;
		list->head = new_node;
	}

	list->size++;

	return new_node;
}

LinkedListNode* ll_add_tail(LinkedList* list, LL_DATA_TYPE data) {
	LinkedListNode* new_node = ll_init_node(data);

	if(!list->head)
		list->head = list->tail = new_node;
	else {
		LinkedListNode* second_node = list->tail;

		new_node->prev = second_node;
		second_node->next = new_node;
		list->tail = new_node;
	}

	list->size++;

	return new_node;
}

bool ll_is_empty(LinkedList* list) {
	return list->size == 0;
}

void ll_clean(LinkedList* list) {
	LinkedListNode* current_node = list->head;

	while(current_node) {
		LinkedListNode* next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

void ll_dispose(LinkedList* list) {
	ll_clean(list);
	free(list);
}

void ll_remove_at(LinkedList* list, unsigned long index) {
	if(index == 0)
		ll_remove_head(list);
	else if(index == list->size - 1)
		ll_remove_tail(list);
	else {
		LinkedListNode* node = ll_get_elem(list, index);
		LinkedListNode* prev_node = node->prev;
		LinkedListNode* next_node = node->next;

		prev_node->next = next_node;
		next_node->prev = prev_node;

		list->size--;

		free(node);
	}
}

void ll_remove_elem(LinkedList* list, LinkedListNode* node) {
	if(node == list->head)
		ll_remove_head(list);
	else if(node == list->tail)
		ll_remove_tail(list);
	else {
		LinkedListNode* prev_node = node->prev;
		LinkedListNode* next_node = node->next;

		prev_node->next = next_node;
		next_node->prev = prev_node;

		list->size--;

		free(node);
	}
}

void ll_remove_head(LinkedList* list) {
	LinkedListNode* first_node = list->head;
	LinkedListNode* second_node = first_node->next;

	list->head = second_node;
	list->size--;

	if(second_node)
		second_node->prev = NULL;

	free(first_node);
}

void ll_remove_tail(LinkedList* list) {
	LinkedListNode* first_node = list->tail;
	LinkedListNode* second_node = first_node->prev;

	list->tail = second_node;
	list->size--;

	if(second_node)
		second_node->next = NULL;

	free(first_node);
}

LinkedListNode* ll_get_elem(LinkedList* list, unsigned long index) {
	LinkedListNode* current_node = list->head;
	for(unsigned long i = 0; i < index; i++)
		current_node = current_node->next;

	return current_node;
}

LL_DATA_TYPE ll_get_data(LinkedList* list, unsigned long index) {
	return ll_get_elem(list, index)->data;
}

void ll_iter_elem(LinkedList* list, void(*function)(LinkedListNode*)) {
	for(LinkedListNode* current_node = list->head; current_node; current_node = current_node->next)
		function(current_node);
}

void ll_iter_elem_index(LinkedList* list, void (*function)(LinkedListNode*, unsigned long)) {
	unsigned long i = 0;
	for(LinkedListNode* current_node = list->head; current_node; current_node = current_node->next, i++)
		function(current_node, i);
}

void ll_iter_data(LinkedList* list, void(*function)(LL_DATA_TYPE)) {
	for(LinkedListNode* current_node = list->head; current_node; current_node = current_node->next)
		function(current_node->data);
}

void ll_iter_data_index(LinkedList* list, void (*function)(LL_DATA_TYPE, unsigned long)) {
	unsigned long i = 0;
	for(LinkedListNode* current_node = list->head; current_node; current_node = current_node->next, i++)
		function(current_node->data, i);
}

void ll_iter_reverse_elem(LinkedList* list, void(*function)(LinkedListNode*)) {
	for(LinkedListNode* current_node = list->tail; current_node; current_node = current_node->prev)
		function(current_node);
}

void ll_iter_reverse_elem_index(LinkedList* list, void (*function)(LinkedListNode*, unsigned long)) {
	unsigned long i = list->size - 1;
	for(LinkedListNode* current_node = list->tail; current_node; current_node = current_node->prev, i--)
		function(current_node, i);
}

void ll_iter_reverse_data(LinkedList* list, void(*function)(LL_DATA_TYPE)) {
	for(LinkedListNode* current_node = list->tail; current_node; current_node = current_node->prev)
		function(current_node->data);
}

void ll_iter_reverse_data_index(LinkedList* list, void (*function)(LL_DATA_TYPE, unsigned long)) {
	unsigned long i = list->size - 1;
	for(LinkedListNode* current_node = list->tail; current_node; current_node = current_node->prev, i--)
		function(current_node->data, i);
}