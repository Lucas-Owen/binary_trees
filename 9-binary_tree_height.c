#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: tree is NULL return 0 else height of tree
 */
/*size_t binary_tree_height(const binary_tree_t *tree)
{
	binary_tree_t *left_t, *right_t;

	size_t height_r = 0;
	size_t height_l = 0;

	if (tree == NULL)
		return (0);
	left_t = tree->left;
	right_t = tree->right;
	while (left_t != NULL)
	{
		height_l++;
		left_t = left_t->left;
	}
	while (right_t != NULL)
	{
		height_r++;
		right_t = right_t->right;
	}
	if (height_r > height_l)
		return (height_r);
	return (height_l);
}*/
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    /* Recursively calculate the heights of the left and right subtrees */
    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    /* Return the maximum of the left and right subtree heights, plus 1 for the root */
    return (1 + (left_height > right_height ? left_height : right_height));
}
