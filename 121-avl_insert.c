#include "binary_trees.h"

/**
 * balance_right_subtree - Balances the subtree assuming it is on the right
 * @tree: The subtree
 */
void balance_right_subtree(avl_t *tree)
{
	if (tree == tree->parent->left &&
		tree->parent == tree->parent->parent->right)
	{
		binary_tree_rotate_right(tree->parent);
		binary_tree_rotate_left(tree->parent);
	}
	else if (tree == tree->parent->right &&
			tree->parent == tree->parent->parent->right)
		binary_tree_rotate_left(tree->parent->parent);
	else
		binary_tree_rotate_right(tree->parent);
}

/**
 * balance_left_subtree - Balances the subtree assuming it is on the left
 * @tree: The subtree
 */
void balance_left_subtree(avl_t *tree)
{
	if (tree == tree->parent->right &&
		tree->parent == tree->parent->parent->left)
	{
		binary_tree_rotate_left(tree->parent);
		binary_tree_rotate_right(tree->parent);
	}
	else if (tree == tree->parent->left &&
			tree->parent == tree->parent->parent->left)
		binary_tree_rotate_right(tree->parent->parent);
	else
		binary_tree_rotate_left(tree->parent);
}

/**
 * check_balance - Checks the balance of an avl tree starting from
 * a newly inserted node. The avl tree is rebalanced if need be
 *
 * @tree: The newly inserted node
 * Return: void
 */
avl_t *check_balance(avl_t *tree)
{
	int balance;

	if (!tree)
		return (NULL);
	if (!tree->parent)
	{
		return (tree);
	}
	balance = binary_tree_balance(tree->parent->parent);
	if (balance < -1)
	{
		balance_right_subtree(tree);
		return (check_balance(tree));
	}
	if (balance > 1)
	{
		balance_left_subtree(tree);
		return (check_balance(tree));
	}
	return (check_balance(tree->parent));
}

/**
 * avl_insert - Insert value to an avl tree
 *
 * @tree: Double pointer to the root of the tree
 * @value: Value to be inserted
 * Return: Pointer to the created node, or NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *subtree;

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
				subtree = subtree->left;
				break;
			}
		}
		else if (value > subtree->n)
		{
			if (subtree->right)
				subtree = subtree->right;
			else
			{
				subtree->right = binary_tree_node(subtree, value);
				subtree = subtree->right;
				break;
			}
		}
		else
			return (NULL);
	}
	*tree = check_balance(subtree);
	return (subtree);
}
