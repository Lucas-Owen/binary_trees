#include "binary_trees.h"

/**
 * _depth - measures the depth of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: tree is NULL return 0 else depth of tree
 */
size_t _depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);
	while (tree->parent)
	{
		tree = tree->parent;
		depth++;
	}
	return (depth);
}

/**
 * _is_complete - Checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the tree
 * @depth: depth of the deepest node
 * Return: int - 1 if complete, 0 otherwise or when root is NULL
 */
int _is_complete(const binary_tree_t *tree, size_t *depth)
{
	size_t node_depth = _depth(tree);

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
	{
		if (*depth == node_depth)
			return (1);
		if (tree->parent->right == tree && *depth - 1 == node_depth)
		{
			(*depth)--;
			return (1);
		}
		return (0);
	}
	if (tree->left && tree->right)
	{
		if (_is_complete(tree->left, depth))
			return (_is_complete(tree->right, depth));
		return (0);
	}
	if (tree->left)
	{
		if (!tree->left->left)
		{
			(*depth)--;
			return (1);
		}
	}
	return (0);
}

/**
 * bin_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: pointer to the root node of the tree
 * Return: int - 1 if complete, 0 otherwise or when root is NULL
 */
int bin_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *node;
	size_t depth;

	if (!tree)
		return (0);
	node = (binary_tree_t *) tree;
	while (node->left)
		node = node->left;
	depth = _depth(node);
	return (_is_complete(tree, &depth));
}

/**
 * _valid_less - Checks that all nodes below are less than a value
 * in a binary tree
 *
 * @tree: Pointer to a node of the tree
 * @value: Current value to compare with
 * Return: 1 if valid, 0 otherwise
 */
int _valid_less(const binary_tree_t *tree, int value)
{
	if (!tree)
		return (0);
	if (tree->n >= value)
		return (0);
	if (tree->left)
	{
		if (!_valid_less(tree->left, value))
			return (0);
	}
	if (tree->right)
	{
		if (!_valid_less(tree->right, value))
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap tree
 *
 * @tree: Root of the tree
 * Return: int - 1 if true, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!bin_tree_is_complete(tree))
		return (0);
	if (tree->left)
	{
		if (!_valid_less(tree->left, tree->n))
			return (0);
		if (!binary_tree_is_heap(tree->left))
			return (0);
	}
	if (tree->right)
	{
		if (!_valid_less(tree->right, tree->n))
			return (0);
		return (binary_tree_is_heap(tree->right));
	}
	return (1);
}

