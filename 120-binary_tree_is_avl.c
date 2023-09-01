#include "binary_trees.h"

/**
 * valid_greater - Checks that all nodes below are greater than value
 * in a binary tree
 *
 * @tree: Pointer to a node of the tree
 * @value: Current value to compare with
 * Return: 1 if valid, 0 otherwise
 */
int valid_greater(const binary_tree_t *tree, int value)
{
	if (!tree)
		return (0);
	if (tree->n <= value)
		return (0);
	if (tree->left)
	{
		if (!valid_greater(tree->left, value))
			return (0);
	}
	if (tree->right)
	{
		if (!valid_greater(tree->right, value))
			return (0);
	}
	return (1);
}

/**
 * valid_less - Checks that all nodes below are less than a value
 * in a binary tree
 *
 * @tree: Pointer to a node of the tree
 * @value: Current value to compare with
 * Return: 1 if valid, 0 otherwise
 */
int valid_less(const binary_tree_t *tree, int value)
{
	if (!tree)
		return (0);
	if (tree->n >= value)
		return (0);
	if (tree->left)
	{
		if (!valid_less(tree->left, value))
			return (0);
	}
	if (tree->right)
	{
		if (!valid_less(tree->right, value))
			return (0);
	}
	return (1);
}

/**
 * avl_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: tree is NULL return 0 else height of tree
 */
size_t avl_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (!tree)
		return (0);
	height_l = tree->left ? 1 + avl_height(tree->left) : 0;
	height_r = tree->right ? 1 + avl_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is an avl tree
 *
 * @tree: Root of the tree
 * Return: int - 1 if true, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t height_l, height_r, diff;

	if (!tree)
		return (0);
	height_l = avl_height(tree->left) + (tree->left ? 1 : 0);
	height_r = avl_height(tree->right) + (tree->right ? 1 : 0);
	diff = height_l > height_r ? height_l - height_r : height_r - height_l;
	if (diff > 1)
		return (0);
	if (tree->left)
	{
		if (!valid_less(tree->left, tree->n))
			return (0);
		if (!binary_tree_is_avl(tree->left))
			return (0);
	}
	if (tree->right)
	{
		if (!valid_greater(tree->right, tree->n))
			return (0);
		return (binary_tree_is_avl(tree->right));
	}
	return (1);
}

