#include "binary_trees.h"
#include <stdlib.h>

/**
 * free_branches - Frees the branches leaving the root
 *
 * @tree: The root of the tree
 */
void free_branches(binary_tree_t *tree)
{
		if (!tree)
			return;
		free_branches(tree->left);
		free(tree->left);
		free_branches(tree->right);
		free(tree->right);
}

/**
 * binary_tree_delete - Deletes an entire binary tree
 *
 * @tree: The root of the tree
 */
void binary_tree_delete(binary_tree_t *tree)
{
	free_branches(tree);
	free(tree);
}
