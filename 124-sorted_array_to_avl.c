#include "binary_trees.h"

/**
 * _insert - Insert value into a binary tree
 * @tree: Root of the tree
 * @value: The value
 */
void _insert(avl_t **tree, int value)
{
	avl_t *subtree;

	if (!tree)
		return;
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return;
	}
	subtree = *tree;
	while (1)
	{
		if (value < subtree->n)
		{
			if (subtree->left)
				subtree = subtree->left;
			else
			{
				subtree->left = binary_tree_node(subtree, value);
				return;
			}
		}
		else if (value > subtree->n)
		{
			if (subtree->right)
				subtree = subtree->right;
			else
			{
				subtree->right = binary_tree_node(subtree, value);
				return;
			}
		}
		else
			return;
	}
}

/**
 * _to_avl - Creates a binary tree from an array
 *
 * @tree: Pointer to pointer to root
 * @array: The array
 * @start: Starting index
 * @stop: Stopping index
 * Return: void
 */
void _to_avl(avl_t **tree, int *array, int start, int stop)
{
	size_t mid = start + (stop - start) / 2;

	if (stop < start)
		return;
	_insert(tree, array[mid]);
	_to_avl(tree, array, start, mid - 1);
	_to_avl(tree, array, mid + 1, stop);
}

/**
 * sorted_array_to_avl - Creates a binary tree from an array
 *
 * @array: The array
 * @size: Size of the array
 * Return: Pointer to the root node created or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	bst_t *tree = NULL;

	if (!array || !size)
		return (NULL);
	_to_avl(&tree, array, 0, size - 1);
	return (tree);
}
