#include "binary_trees.h"

/**
  * binary_tree_size -  measures the size of a binary tree
  * @tree: pointer to the root node of the tree to measure the size
  * Return: If tree is NULL, the function return 0 else size
  */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size_r, size_l;

	if (!tree)
		return (0);
	size_r = binary_tree_size(tree->right);
	size_l = binary_tree_size(tree->left);
	return (1 + size_r + size_l);
}
