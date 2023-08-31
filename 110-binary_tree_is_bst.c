#include "binary_trees.h"

/**
 * is_valid_greater - Checks that all nodes below are greater than value
 * in a binary tree
 *
 * @tree: Pointer to a node of the tree
 * @value: Current value to compare with
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_greater(const binary_tree_t *tree, int value)
{
	if (!tree)
		return (0);
	if (tree->n < value)
		return (0);
	if (tree->left)
	{
		if (!is_valid_greater(tree->left, value))
			return (0);
	}
	if (tree->right)
	{
		if (!is_valid_greater(tree->right, value))
			return (0);
	}
	return (1);
}

/**
 * is_valid_less - Checks that all nodes below are less than a value
 * in a binary tree
 *
 * @tree: Pointer to a node of the tree
 * @value: Current value to compare with
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_less(const binary_tree_t *tree, int value)
{
	if (!tree)
		return (0);
	if (tree->n > value)
		return (0);
	if (tree->left)
	{
		if (!is_valid_less(tree->left, value))
			return (0);
	}
	if (tree->right)
	{
		if (!is_valid_less(tree->right, value))
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks whether a binary tree is a valid bst
 *
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if valid, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left)
	{
		if (!is_valid_less(tree->left, tree->n))
			return (0);
		if (!binary_tree_is_bst(tree->left))
			return (0);
	}
	if (tree->right)
	{
		if (!is_valid_greater(tree->right, tree->n))
			return (0);
		if (!binary_tree_is_bst(tree->right))
			return (0);
	}
	return (1);
}
