#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if the tree is full
 *
 * @tree: pointer to the root node of the tree
 * Return: 0 if tree is null or not full, 1 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && tree->right)
	{
		if (binary_tree_is_full(tree->left))
			return (binary_tree_is_full(tree->right));
	}
	return (0);
}
