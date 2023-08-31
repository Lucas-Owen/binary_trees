#include "binary_trees.h"

/**
 * release_root - Detaches root from the tree, replacing it
 * with its next in-order element in the tree
 *
 * @root: The node to be detached
 * Return: The new root of the tree after rearranging pointers
 */
bst_t *release_root(bst_t *root)
{
	bst_t *next_in_order = root->left;

	if (root->right)
	{
		next_in_order = root->right;
		while (next_in_order->left)
			next_in_order = next_in_order->left;
	}
	if (root->parent)
	{
		if (root->parent->right == root)
			root->parent->right = next_in_order;
		else
			root->parent->left = next_in_order;
	}
	if (next_in_order)
	{
		if (next_in_order->parent->right == next_in_order)
			next_in_order->parent->right = NULL;
		else
			next_in_order->parent->left = NULL;
		next_in_order->parent = root->parent;
		if (!next_in_order->left && next_in_order != root->left)
		{
			next_in_order->left = root->left;
			if (root->left)
				root->left->parent = next_in_order;
		}
		if (!next_in_order->right && next_in_order != root->right)
		{
			next_in_order->right = root->right;
			if (root->right)
				root->right->parent = next_in_order;
		}
		root = next_in_order;
	}
	while (root && root->parent)
		root = root->parent;
	return (root);
}

/**
 * bst_remove - Remove a node with value from a bstree
 *
 * @root: Pointer to the root of the bst
 * @value: Value to remove
 * Return: Pointer to the root node of the tree after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *new_root = root;

	if (!root)
		return (NULL);
	if (value < root->n && root->left)
		return (bst_remove(root->left, value));
	if (value > root->n && root->right)
		return (bst_remove(root->right, value));
	if (value == root->n)
	{
		new_root = release_root(root);
		free(root);
	}
	return (new_root);
}
