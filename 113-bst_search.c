#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a bst
 *
 * @tree: Pointer to the root node of the BST
 * @value: Value to search for
 * Return: Pointer to a node containing value, or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	if (value > tree->n)
		return (bst_search(tree->right, value));
	return ((bst_t *) tree);
}
