#include "binary_trees.h"

/**
  * binary_tree_leaves - counts the leaves in a binary tree
  * @tree: pointer to the root node of the tree to count the number of leaves
  * Return: If tree is NULL, the function must return 0
  */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t r_leaf, l_leaf;

	if (!tree)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	r_leaf = binary_tree_leaves(tree->right);
	l_leaf = binary_tree_leaves(tree->left);
	return (r_leaf + l_leaf);
}
