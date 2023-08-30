#include "binary_trees.h"

/**
 * find - Checks if a value is present in a tree
 *
 * @tree: Pointer to the binary tree
 * @value: Value to find
 * Return: int - 1 if found, 0 otherwise
 */
int find(const binary_tree_t *tree, int value)
{
	if (!tree)
		return (0);
	if (tree->n == value)
		return (1);
	if (find(tree->left, value))
		return (1);
	return (find(tree->right, value));
}

/**
 * get_depth - measures the depth of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: tree is NULL return 0 else depth of tree
 */
size_t get_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);
	while (tree->parent)
	{
		tree = tree->parent;
		depth++;
	}
	return (depth);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor between two nodes
 *
 * @first: First node
 * @second: Second node
 * Return: binary_tree_t* - Pointer to the ancestor or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *start;
	int value;

	if (!first || !second)
		return (NULL);
	start = get_depth(first) < get_depth(second) ? first : second;
	value = start == first ? second->n : first->n;
	while (start)
	{
		if (find(start, value))
			return ((binary_tree_t *) start);
		start = start->parent;
	}
	return (NULL);
}
