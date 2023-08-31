#include "binary_trees.h"

/**
 * array_to_bst - Creates a binary tree from an array
 *
 * @array: The array
 * @size: Size of the array
 * Return: Pointer to the root node created or NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	if (!array || !size)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		bst_insert(&tree, array[i]);
	}
	return (tree);
}
