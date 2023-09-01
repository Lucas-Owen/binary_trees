#include "binary_trees.h"

/**
 * new_list - Requests memory for a new list and exits on failure
 * Return: my_list* - Pointer to the new my_list
 */
my_list *new_list()
{
	my_list *ptr = malloc(sizeof(my_list));

	if (ptr)
		return (ptr);
	exit(1);
}

/**
 * append_node - Appends a new node after the given node
 * @last: Last node of a list
 * @tree: Value of tree at new list node
 */
void append_node(my_list *last, binary_tree_t *tree)
{
	last->next = new_list();
	last = last->next;
	last->tree = tree;
	last->next = NULL;
}

/**
 * binary_tree_levelorder - Performs a levelorder traversal on the tree
 *
 * @tree: Pointer to the root of the tree
 * @func: Function to apply to data
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	my_list *nodes, *last, *curr;

	if (!tree || !func)
		return;

	nodes = new_list();
	last = nodes, curr = nodes;
	nodes->tree = tree;
	nodes->next = NULL;
	while (curr)
	{
		func(curr->tree->n);
		if (curr->tree->left)
		{
			append_node(last, curr->tree->left);
			last = last->next;
		}
		if (curr->tree->right)
		{
			append_node(last, curr->tree->right);
			last = last->next;
		}
		curr = curr->next;
	}
	while (nodes)
	{
		curr = nodes->next;
		free(nodes);
		nodes = curr;
	}
}
