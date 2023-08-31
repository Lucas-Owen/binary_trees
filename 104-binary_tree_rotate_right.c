#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree
 *
 * @tree: The node to rotate
 * Return: binary_tree_t* - Pointer to the root or NULL
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_parent = NULL;
	binary_tree_t *grand_parent = NULL;
	binary_tree_t *new_left = NULL;

	if (!tree)
		return (NULL);
	grand_parent = tree->parent;
	new_parent = tree->left;
	if (new_parent)
	{
		new_left = new_parent->right;
		new_parent->parent = grand_parent;
		if (grand_parent)
		{
			if (grand_parent->right == tree)
				grand_parent->right = new_parent;
			else
				grand_parent->left = new_parent;
		}
		new_parent->right = tree;
	}
	tree->left = new_left;
	tree->parent = new_parent;
	while (tree->parent)
		tree = tree->parent;
	return (tree);
}
