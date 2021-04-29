#include "pch.h"
#include <stdlib.h>

BinaryTreeNode* bt_init_node(BT_DATA_TYPE data) {
	BinaryTreeNode* new_node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));

	if(new_node) {
		new_node->data = data;
		new_node->level = 0;

		new_node->parent = NULL;
		new_node->left = NULL;
		new_node->right = NULL;
	}

	return new_node;
}

BinaryTreeNode* bt_add_left(BinaryTreeNode* parent_node, BT_DATA_TYPE data) {
	BinaryTreeNode* new_node = bt_init_node(data);
	new_node->parent = parent_node;
	new_node->level = parent_node->level + 1;

	parent_node->left = new_node;

	return new_node;
}

BinaryTreeNode* bt_add_right(BinaryTreeNode* parent_node, BT_DATA_TYPE data) {
	BinaryTreeNode* new_node = bt_init_node(data);
	new_node->parent = parent_node;
	new_node->level = parent_node->level + 1;

	parent_node->right = new_node;

	return new_node;
}

void bt_iter_elem_preorder(BinaryTreeNode* root_node, void(*function)(BinaryTreeNode*)) {
	if(!root_node)
		return;

	function(root_node);
	bt_iter_elem_preorder(root_node->left, function);
	bt_iter_elem_preorder(root_node->right, function);
}

void bt_iter_data_preorder(BinaryTreeNode* root_node, void(*function)(BT_DATA_TYPE)) {
	if(!root_node)
		return;
	
	function(root_node->data);
	bt_iter_data_preorder(root_node->left, function);
	bt_iter_data_preorder(root_node->right, function);
}

void bt_iter_elem_inorder(BinaryTreeNode* root_node, void(*function)(BinaryTreeNode*)) {
	if(!root_node)
		return;

	bt_iter_elem_inorder(root_node->left, function);
	function(root_node);
	bt_iter_elem_inorder(root_node->right, function);
}

void bt_iter_data_inorder(BinaryTreeNode* root_node, void(*function)(BT_DATA_TYPE)) {
	if(!root_node)
		return;

	bt_iter_data_inorder(root_node->left, function);
	function(root_node->data);
	bt_iter_data_inorder(root_node->right, function);
}

void bt_iter_elem_postorder(BinaryTreeNode* root_node, void(*function)(BinaryTreeNode*)) {
	if(!root_node)
		return;

	bt_iter_elem_postorder(root_node->left, function);
	bt_iter_elem_postorder(root_node->right, function);
	function(root_node);
}

void bt_iter_data_postorder(BinaryTreeNode* root_node, void(*function)(BT_DATA_TYPE)) {
	if(!root_node)
		return;

	bt_iter_data_postorder(root_node->left, function);
	bt_iter_data_postorder(root_node->right, function);
	function(root_node->data);
}

void bt_iter_elem_levelorder(BinaryTreeNode* root_node, void(*function)(BinaryTreeNode*)) {

}

void bt_iter_data_levelorder(BinaryTreeNode* root_node, void(*function)(BT_DATA_TYPE)) {

}

void bt_dispose(BinaryTreeNode* root_node) {
	bt_iter_elem_postorder(root_node, free);
}
