#include "binary_trees.h"

/**
 * node_is_leaf - Checks if a node is a leaf
 *
 * @node: Pointer to the node to check
 * Return: int - 1 if node is leaf, 0 otherwise
 */
int node_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->left || node->right)
		return (0);
	return (1);
}


/**
 * tree_depth - measures the depth of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: tree is NULL return 0 else depth of tree
 */
size_t tree_depth(const binary_tree_t *tree)
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
 * tree_is_perfect - Checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree
 * @depth: depth of the deepest node
 * Return: int - 1 if perfect, 0 otherwise or when root is NULL
 */
int tree_is_perfect(const binary_tree_t *tree, size_t depth)
{
	if (!tree)
		return (0);
	if (node_is_leaf(tree))
	{
		if (depth != tree_depth(tree))
			return (0);
		return (1);
	}
	if (tree->left && tree->right)
	{
		if (tree_is_perfect(tree->left, depth))
			return (tree_is_perfect(tree->right, depth));
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
	binary_tree_t *node;
	size_t depth;

	if (!tree)
		return (0);
	node = (binary_tree_t *) tree;
	while (node->left)
		node = node->left;
	depth = tree_depth(node);
	return (tree_is_perfect(tree, depth));
}
