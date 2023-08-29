#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - Inserts a node as the right child of another node
 *
 * @parent: Pointer to the node to insert the right child in (NOT NULL)
 * @value: Value to store in the new node
 * Return: binary_tree_t* - Pointer to the new node or NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (!parent)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->left = NULL;
	node->parent = parent;

	node->right = parent->right;
	parent->right = node;
	if (node->right)
		node->right->parent = node;
	return (node);
}
