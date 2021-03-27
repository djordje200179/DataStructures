#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

typedef void* SLL_DATA_TYPE;

typedef struct SingleLinkedListNode {
	SLL_DATA_TYPE data;
	struct SingleLinkedListNode* next;
} SingleLinkedListNode;

typedef struct SingleLinkedList {
	SingleLinkedListNode* head;
	SingleLinkedListNode* tail;
	unsigned int size;
} SingleLinkedList;

SingleLinkedList* sll_init_list();
SingleLinkedListNode* sll_init_node(SLL_DATA_TYPE data);

SingleLinkedListNode* sll_add_at(SingleLinkedList* list, unsigned long index, SLL_DATA_TYPE data);
SingleLinkedListNode* sll_add_after(SingleLinkedList* list, SingleLinkedListNode* prev_node, SLL_DATA_TYPE data);
SingleLinkedListNode* sll_add_head(SingleLinkedList* list, SLL_DATA_TYPE data);
SingleLinkedListNode* sll_add_tail(SingleLinkedList* list, SLL_DATA_TYPE data);

void sll_clean(SingleLinkedList* list);

void sll_remove_at(SingleLinkedList* list, unsigned long index);
void sll_remove_elem(SingleLinkedList* list, SingleLinkedListNode* node);
void sll_remove_head(SingleLinkedList* list);
void sll_remove_tail(SingleLinkedList* list);

SingleLinkedListNode* sll_get_elem(SingleLinkedList* list, unsigned long index);
SLL_DATA_TYPE sll_get_data(SingleLinkedList* list, unsigned long index);

void sll_iter_elem(SingleLinkedList* list, void (*function)(SingleLinkedListNode*));
void sll_iter_elem_index(SingleLinkedList* list, void (*function)(SingleLinkedListNode*, unsigned long));
void sll_iter_data(SingleLinkedList* list, void (*function)(SLL_DATA_TYPE));
void sll_iter_data_index(SingleLinkedList* list, void (*function)(SLL_DATA_TYPE, unsigned long));

#endif //SINGLE_LINKED_LIST