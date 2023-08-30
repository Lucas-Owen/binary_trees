#include "binary_trees.h"

/**
 * bal_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: tree is NULL return 0 else height of tree
 */
size_t bal_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (!tree)
		return (0);
	height_l = tree->left ? 1 + bal_height(tree->left) : 0;
	height_r = tree->right ? 1 + bal_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_balance - measures the balance of a binary tree
 *
 * @tree: pointer to the root node of the tree
 * Return: tree is NULL return 0 else balance of tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	left = tree->left ? 1 + bal_height(tree->left) : 0;
	right = tree->right ? 1 + bal_height(tree->right) : 0;
	return (left - right);
}
