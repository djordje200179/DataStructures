#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

typedef void* DLL_DATA_TYPE;

typedef struct DoubleLinkedListNode {
	DLL_DATA_TYPE data;
	struct DoubleLinkedListNode* prev;
	struct DoubleLinkedListNode* next;
} DoubleLinkedListNode;

typedef struct DoubleLinkedList {
	DoubleLinkedListNode* head;
	DoubleLinkedListNode* tail;
	unsigned int size;
} DoubleLinkedList;

DoubleLinkedList* dll_init_list();
DoubleLinkedListNode* dll_init_node(DLL_DATA_TYPE data);

DoubleLinkedListNode* dll_add_at(DoubleLinkedList* list, unsigned long index, DLL_DATA_TYPE data);
DoubleLinkedListNode* dll_add_after(DoubleLinkedList* list, DoubleLinkedListNode* prev_node, DLL_DATA_TYPE data);
DoubleLinkedListNode* dll_add_head(DoubleLinkedList* list, DLL_DATA_TYPE data);
DoubleLinkedListNode* dll_add_tail(DoubleLinkedList* list, DLL_DATA_TYPE data);

void dll_clean(DoubleLinkedList* list);

void dll_remove_at(DoubleLinkedList* list, unsigned long index);
void dll_remove_elem(DoubleLinkedList* list, DoubleLinkedListNode* node);
void dll_remove_head(DoubleLinkedList* list);
void dll_remove_tail(DoubleLinkedList* list);

DoubleLinkedListNode* dll_get_elem(DoubleLinkedList* list, unsigned long index);
DLL_DATA_TYPE dll_get_data(DoubleLinkedList* list, unsigned long index);

void dll_iter_elem(DoubleLinkedList* list, void (*function)(DoubleLinkedListNode*));
void dll_iter_elem_index(DoubleLinkedList* list, void (*function)(DoubleLinkedListNode*, unsigned long));
void dll_iter_data(DoubleLinkedList* list, void (*function)(DLL_DATA_TYPE));
void dll_iter_data_index(DoubleLinkedList* list, void (*function)(DLL_DATA_TYPE, unsigned long));
void dll_iter_reverse_elem(DoubleLinkedList* list, void (*function)(DoubleLinkedListNode*));
void dll_iter_reverse_elem_index(DoubleLinkedList* list, void (*function)(DoubleLinkedListNode*, unsigned long));
void dll_iter_reverse_data(DoubleLinkedList* list, void (*function)(DLL_DATA_TYPE));
void dll_iter_reverse_data_index(DoubleLinkedList* list, void (*function)(DLL_DATA_TYPE, unsigned long));

#endif //DOUBLE_LINKED_LIST