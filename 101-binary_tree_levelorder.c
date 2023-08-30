#include "binary_trees.h"

/**
 * binary_tree_levelorder - Performs a levelorder traversal on the tree
 *
 * @tree: Pointer to the root of the tree
 * @func: Function to apply to data
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	my_list *nodes = malloc(sizeof(my_list));
	my_list *last = nodes, *curr = nodes;

	nodes->tree = tree;
	nodes->next = NULL;
	while (curr)
	{
		if (curr->tree->left)
		{
			last->next = malloc(sizeof(my_list));
			last->next->tree = curr->tree->left;
			last->next->next = NULL;
			last = last->next;
		}
		if (curr->tree->right)
		{
			last->next = malloc(sizeof(my_list));
			last->next->tree = curr->tree->right;
			last->next->next = NULL;
			last = last->next;
		}
		func(curr->tree->n);
		curr = curr->next;
	}
	while (nodes)
	{
		curr = nodes->next;
		free(nodes);
		nodes = curr;
	}
}
