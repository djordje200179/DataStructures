#include "binary_tree.h"
#include <stdio.h>

void print_char(void* data);

void bt_test() {
	const char data[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };

	BinaryTreeNode* a = bt_init_node(&data[0]);
	BinaryTreeNode* b = bt_add_left(a, &data[1]);
	BinaryTreeNode* c = bt_add_right(a, &data[2]);
	BinaryTreeNode* d = bt_add_left(b, &data[3]);
	BinaryTreeNode* e = bt_add_right(b, &data[4]);
	BinaryTreeNode* f = bt_add_left(c, &data[5]);
	BinaryTreeNode* g = bt_add_right(c, &data[6]);

	printf("Binary tree:\n");
	printf("-preorder: ");
	bt_iter_data_preorder(a, print_char);
	printf("\n");
	printf("-inorder: ");
	bt_iter_data_inorder(a, print_char);
	printf("\n");
	printf("-postorder: ");
	bt_iter_data_postorder(a, print_char);
	printf("\n");
	printf("\n");

	bt_dispose(a);
}