#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: tree is NULL return 0 else depth of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
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
