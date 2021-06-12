#ifndef BINARY_TREE
#define BINARY_TREE

typedef void* BT_DATA_TYPE;

typedef struct BinaryTreeNode {
	BT_DATA_TYPE data;
	unsigned int level;

	struct BinaryTreeNode* parent;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
} BinaryTreeNode;

BinaryTreeNode* bt_init_node(const BT_DATA_TYPE data);

BinaryTreeNode* bt_add_left(BinaryTreeNode* parent_node, const BT_DATA_TYPE data);
BinaryTreeNode* bt_add_right(BinaryTreeNode* parent_node, const BT_DATA_TYPE data);

void bt_iter_elem_preorder(BinaryTreeNode* root_node, const void (*function)(BinaryTreeNode*));
void bt_iter_data_preorder(BinaryTreeNode* root_node, const void (*function)(BT_DATA_TYPE));
void bt_iter_elem_inorder(BinaryTreeNode* root_node, const void (*function)(BinaryTreeNode*));
void bt_iter_data_inorder(BinaryTreeNode* root_node, const void (*function)(BT_DATA_TYPE));
void bt_iter_elem_postorder(BinaryTreeNode* root_node, const void (*function)(BinaryTreeNode*));
void bt_iter_data_postorder(BinaryTreeNode* root_node, const void (*function)(BT_DATA_TYPE));
void bt_iter_elem_levelorder(BinaryTreeNode* root_node, const void (*function)(BinaryTreeNode*));
void bt_iter_data_levelorder(BinaryTreeNode* root_node, const void (*function)(BT_DATA_TYPE));

void bt_dispose(BinaryTreeNode* root_node);

#endif //BINARY_TREE