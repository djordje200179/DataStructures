#include <DataStructures/binary_tree.h>
#include "misc.h"
#include <stdio.h>

void bt_test() {
	set_text_color(GREEN_COLOR);
	printf("Binary tree:\n");
	set_text_color(NO_COLOR);

	BinaryTreeNode* a = bt_init_node(char_to_ptr('A'));
	BinaryTreeNode* b = bt_add_left(a, char_to_ptr('B'));
	BinaryTreeNode* c = bt_add_right(a, char_to_ptr('C'));
	BinaryTreeNode* d = bt_add_left(b, char_to_ptr('D'));
	BinaryTreeNode* e = bt_add_right(b, char_to_ptr('E'));
	BinaryTreeNode* f = bt_add_left(c, char_to_ptr('F'));
	BinaryTreeNode* g = bt_add_right(c, char_to_ptr('G'));

	printf("-preorder: ");
	bt_iter_data_preorder(a, print_char);
	printf("\n");
	printf("-inorder: ");
	bt_iter_data_inorder(a, print_char);
	printf("\n");
	printf("-postorder: ");
	bt_iter_data_postorder(a, print_char);
	printf("\n");

	bt_dispose(a);
}