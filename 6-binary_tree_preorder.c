#include "binary_trees.h"

/**
 * binary_tree_preorder - Pre-order traversal of a binary tree
 *
 * @tree: Pointer to the root of the tree to traverse
 * @func: A pointer to a function call for each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
