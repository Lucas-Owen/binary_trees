#include "binary_trees.h"
#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: tree is NULL return 0 else height of tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (!tree)
		return (0);
	height_l = tree->left ? 1 + tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * tree_balance - measures the balance of a binary tree
 *
 * @tree: pointer to the root node of the tree
 * Return: tree is NULL return 0 else balance of tree
 */
int tree_balance(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	left = tree->left ? 1 + tree_height(tree->left) : 0;
	right = tree->right ? 1 + tree_height(tree->right) : 0;
	return (left - right);
}

/**
 * tree_is_full - Checks if the tree is full
 *
 * @tree: pointer to the root node of the tree
 * Return: 0 if tree is null or not full, 1 otherwise
 */
int tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && tree->right)
	{
		if (tree_is_full(tree->left))
			return (tree_is_full(tree->right));
	}
	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree
 * Return: int - 1 if perfect, 0 otherwise or when root is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree_balance(tree) == 0 && tree_is_full(tree))
		return (1);
	return (0);
}
