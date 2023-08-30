#include "binary_trees.h"

/**
 * binary_tree_sibling - Returns the sibling of a node
 *
 * @node: The node to find the sibling
 * Return: binary_tree_t* - the sibling or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (!node || !node->parent)
		return (NULL);
	parent = node->parent;
	return (node == parent->left ? parent->right : parent->left);
}
