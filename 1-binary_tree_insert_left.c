#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - Inserts a node as the left child of another node
 *
 * @parent: Pointer to the node to insert the left child in (NOT NULL)
 * @value: Value to store in the new node
 * Return: binary_tree_t* - Pointer to the new node or NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (!parent)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->n = value;
	node->right = NULL;
	node->parent = parent;

	node->left = parent->left;
	parent->left = node;
	if (node->left)
		node->left->parent = node;
	return (node);
}
