#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a given node is a root
 *
 * @node: Pointer to the node to check
 * Return: int - 1 if node is root, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);
	return (node->parent ? 0 : 1);
}
