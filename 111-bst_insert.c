#include "binary_trees.h"

/**
 * bst_insert - Insert value to a bst
 *
 * @tree: Double pointer to the root of the tree
 * @value: Value to be inserted
 * Return: Pointer to the created node, or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *subtree;

	if (!tree)
		return (NULL);
	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
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
				return (subtree->left);
			}
		}
		else if (value > subtree->n)
		{
			if (subtree->right)
				subtree = subtree->right;
			else
			{
				subtree->right = binary_tree_node(subtree, value);
				return (subtree->right);
			}
		}
		else
			return (NULL);
	}
}
