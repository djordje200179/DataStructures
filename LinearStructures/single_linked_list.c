#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

SingleLinkedList* sll_init_list() {
	SingleLinkedList* new_list = (SingleLinkedList*)malloc(sizeof(SingleLinkedList));

	if(new_list) {
		new_list->head = NULL;
		new_list->tail = NULL;
		new_list->size = 0;
	}

	return new_list;
}

SingleLinkedListNode* sll_init_node(SLL_DATA_TYPE data) {
	SingleLinkedListNode* new_node = (SingleLinkedListNode*)malloc(sizeof(SingleLinkedListNode));

	if(new_node) {
		new_node->data = data;
		new_node->next = NULL;
	}

	return new_node;
}

SingleLinkedListNode* sll_add_at(SingleLinkedList* list, unsigned long index, SLL_DATA_TYPE data) {
	if(index == 0)
		return sll_add_head(list, data);
	if(index == list->size - 1)
		return sll_add_tail(list, data);
	else {
		SingleLinkedListNode* node = sll_get_elem(list, index);
		SingleLinkedListNode* next_node = node->next;
		SingleLinkedListNode* new_node = sll_init_node(node->data);

		node->data = data;
		node->next = new_node;
		new_node->next = next_node;

		list->size++;

		return new_node;
	}
}

SingleLinkedListNode* sll_add_after(SingleLinkedList* list, SingleLinkedListNode* prev_node, SLL_DATA_TYPE data) {
	SingleLinkedListNode* next_node = prev_node->next;
	SingleLinkedListNode* new_node = sll_init_node(data);

	prev_node->next = new_node;
	new_node->next = next_node;

	list->size++;

	return new_node;
}

SingleLinkedListNode* sll_add_head(SingleLinkedList* list, SLL_DATA_TYPE data) {
	SingleLinkedListNode* new_node = sll_init_node(data);

	if(list->head == NULL)
		list->head = list->tail = new_node;
	else {
		SingleLinkedListNode* second_node = list->head;

		new_node->next = second_node;
		list->head = new_node;
	}

	list->size++;

	return new_node;
}

SingleLinkedListNode* sll_add_tail(SingleLinkedList* list, SLL_DATA_TYPE data) {
	SingleLinkedListNode* new_node = sll_init_node(data);

	if(list->head == NULL)
		list->head = list->tail = new_node;
	else {
		SingleLinkedListNode* second_node = list->tail;

		second_node->next = new_node;
		list->tail = new_node;
	}

	list->size++;

	return new_node;
}

void sll_clean(SingleLinkedList* list) {
	SingleLinkedListNode* current_node = list->head;

	while(current_node) {
		SingleLinkedListNode* next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	list->head = list->tail = NULL;
	list->size = 0;
}

void sll_remove_at(SingleLinkedList* list, unsigned long index) {
	if(index == 0)
		sll_remove_head(list);
	else if(index == list->size - 1)
		sll_remove_tail(list);
	else {
		SingleLinkedListNode* prev_node = sll_get_elem(list, index - 1);
		SingleLinkedListNode* node = prev_node->next;
		SingleLinkedListNode* next_node = node->next;

		prev_node->next = next_node;

		list->size--;

		free(node);
	}
}

void sll_remove_elem(SingleLinkedList* list, SingleLinkedListNode* node) {
	if(node == list->head)
		sll_remove_head(list);
	else if(node == list->tail)
		sll_remove_tail(list);
	else {
		SingleLinkedListNode* prev_node;
		for(prev_node = list->head; prev_node->next != node; prev_node = prev_node->next);
		SingleLinkedListNode* next_node = node->next;

		prev_node->next = next_node;

		list->size--;

		free(node);
	}
}

void sll_remove_head(SingleLinkedList* list) {
	SingleLinkedListNode* first_node = list->head;
	SingleLinkedListNode* second_node = first_node->next;

	list->head = second_node;
	list->size--;

	free(first_node);
}

void sll_remove_tail(SingleLinkedList* list) {
	SingleLinkedListNode* first_node = list->tail;
	SingleLinkedListNode* second_node = sll_get_elem(list, list->size - 2);

	list->tail = second_node;
	list->size--;

	if(second_node)
		second_node->next = NULL;

	free(first_node);
}

SingleLinkedListNode* sll_get_elem(SingleLinkedList* list, unsigned long index) {
	SingleLinkedListNode* current_node = list->head;
	for(unsigned long i = 0; i < index; i++)
		current_node = current_node->next;

	return current_node;
}

SLL_DATA_TYPE sll_get_data(SingleLinkedList* list, unsigned long index) {
	return sll_get_elem(list, index)->data;
}

void sll_iter_elem(SingleLinkedList* list, void(*function)(SingleLinkedListNode*)) {
	for(SingleLinkedListNode* current_node = list->head; current_node; current_node = current_node->next)
		function(current_node);
}

void sll_iter_elem_index(SingleLinkedList* list, void (*function)(SingleLinkedListNode*, unsigned long)) {
	unsigned long i = 0;
	for(SingleLinkedListNode* current_node = list->head; current_node; current_node = current_node->next, i++)
		function(current_node, i);
}

void sll_iter_data(SingleLinkedList* list, void(*function)(SLL_DATA_TYPE)) {
	for(SingleLinkedListNode* current_node = list->head; current_node; current_node = current_node->next)
		function(current_node->data);
}

void sll_iter_data_index(SingleLinkedList* list, void (*function)(SLL_DATA_TYPE, unsigned long)) {
	unsigned long i = 0;
	for(SingleLinkedListNode* current_node = list->head; current_node; current_node = current_node->next, i++)
		function(current_node->data, i);
}