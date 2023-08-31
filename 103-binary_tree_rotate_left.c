#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree
 *
 * @tree: The node to rotate
 * Return: binary_tree_t* - Pointer to the root or NULL
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_parent = NULL;
	binary_tree_t *grand_parent = NULL;
	binary_tree_t *new_right = NULL;

	if (!tree)
		return (NULL);
	grand_parent = tree->parent;
	new_parent = tree->right;
	if (new_parent)
	{
		new_right = new_parent->left;
		new_parent->parent = grand_parent;
		if (grand_parent)
		{
			if (grand_parent->left == tree)
				grand_parent->left = new_parent;
			else
				grand_parent->right = new_parent;
		}
		new_parent->left = tree;
	}
	tree->right = new_right;
	tree->parent = new_parent;
	while (tree->parent)
		tree = tree->parent;
	return (tree);
}
