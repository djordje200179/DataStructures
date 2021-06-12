#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdbool.h>

typedef void* LL_DATA_TYPE;

typedef struct LinkedListNode {
	LL_DATA_TYPE data;

	struct LinkedListNode* prev;
	struct LinkedListNode* next;
} LinkedListNode;

typedef struct LinkedList {
	unsigned int size;

	LinkedListNode* head;
	LinkedListNode* tail;
} LinkedList;

LinkedList* ll_init();
LinkedListNode* ll_init_node(const LL_DATA_TYPE data);

LinkedListNode* ll_add_at(LinkedList* list, const unsigned long index, const LL_DATA_TYPE data);
LinkedListNode* ll_add_after(LinkedList* list, LinkedListNode* prev_node, const LL_DATA_TYPE data);
LinkedListNode* ll_add_head(LinkedList* list, const LL_DATA_TYPE data);
LinkedListNode* ll_add_tail(LinkedList* list, const LL_DATA_TYPE data);

bool ll_is_empty(const LinkedList* list);

void ll_clean(LinkedList* list);
void ll_dispose(LinkedList* list);

void ll_remove_at(LinkedList* list, const unsigned long index);
void ll_remove_elem(LinkedList* list, LinkedListNode* node);
void ll_remove_head(LinkedList* list);
void ll_remove_tail(LinkedList* list);

LinkedListNode* ll_get_elem(const LinkedList* list, const unsigned long index);
LL_DATA_TYPE ll_get_data(const LinkedList* list, const unsigned long index);

void ll_iter_elem(const LinkedList* list, const void (*function)(LinkedListNode*));
void ll_iter_elem_index(const LinkedList* list, const void (*function)(LinkedListNode*, unsigned long));
void ll_iter_data(const LinkedList* list, const void (*function)(LL_DATA_TYPE));
void ll_iter_data_index(const LinkedList* list, const void (*function)(LL_DATA_TYPE, unsigned long));
void ll_iter_reverse_elem(const LinkedList* list, const void (*function)(LinkedListNode*));
void ll_iter_reverse_elem_index(const LinkedList* list, const void (*function)(LinkedListNode*, unsigned long));
void ll_iter_reverse_data(const LinkedList* list, const void (*function)(LL_DATA_TYPE));
void ll_iter_reverse_data_index(const LinkedList* list, const void (*function)(LL_DATA_TYPE, unsigned long));

#endif // LINKED_LIST