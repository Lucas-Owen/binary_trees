#include "binary_trees.h"

/**
 * rotate_and_balance - Balances the subtree given the balance
 * @tree: The subtree
 * @balance: Balance
 */
void rotate_and_balance(avl_t *tree, int balance)
{
	if (balance < -1)
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
	if (balance > 1)
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

}

/**
 * rebalance_tree - Checks the balance of an avl tree starting from
 * a node whose child has been deleted
 * The avl tree is rebalanced if need be
 *
 * @tree: The newly inserted node
 * Return: Pointer to the new root
 */
avl_t *rebalance_tree(avl_t *tree)
{
	int balance;

	if (!tree)
		return (NULL);
	if (!tree->parent)
	{
		return (tree);
	}
	balance = binary_tree_balance(tree->parent->parent);
	if (balance < -1 || balance > 1)
	{
		rotate_and_balance(tree, balance);
		return (rebalance_tree(tree));
	}
	return (rebalance_tree(tree->parent));
}

/**
 * release - Detaches root from the tree, replacing it
 * with its next in-order element in the tree
 *
 * @root: The node to be detached
 * Return: The next in-order node or the parent of the deleted node
 */
avl_t *release(avl_t *root)
{
	avl_t *next_in_order = root->left;

	if (root->right)
	{
		next_in_order = root->right;
		while (next_in_order->left)
			next_in_order = next_in_order->left;
	}
	if (root->parent)
	{
		if (root->parent->right == root)
			root->parent->right = next_in_order;
		else
			root->parent->left = next_in_order;
	}
	if (next_in_order)
	{
		if (next_in_order->parent->right == next_in_order)
			next_in_order->parent->right = NULL;
		else
			next_in_order->parent->left = NULL;
		next_in_order->parent = root->parent;
		if (!next_in_order->left && next_in_order != root->left)
		{
			next_in_order->left = root->left;
			if (root->left)
				root->left->parent = next_in_order;
		}
		if (!next_in_order->right && next_in_order != root->right)
		{
			next_in_order->right = root->right;
			if (root->right)
				root->right->parent = next_in_order;
		}
	}
	return (next_in_order ? next_in_order : root->parent);
}


/**
 * node_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: tree is NULL return 0 else height of tree
 */
size_t node_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (!tree)
		return (0);
	height_l = 1 + node_height(tree->left);
	height_r = 1 + node_height(tree->right);
	return (height_l > height_r ? height_l : height_r);
}

/**
 * avl_remove - Remove a node with value from a avlree
 *
 * @root: Pointer to the root of the avl
 * @value: Value to remove
 * Return: Pointer to the root node of the tree after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *new_root = root, *node;
	int balance, left_b, right_b;

	if (!root)
		return (NULL);
	if (value < root->n && root->left)
		return (avl_remove(root->left, value));
	if (value > root->n && root->right)
		return (avl_remove(root->right, value));
	if (value == root->n)
	{
		node = release(root);
		free(root);
		if (!node)
			return (NULL);
		if (node->right)
		{
			node = node->right;
			while (node->left)
				node = node->left;
		}
		do {
			balance = binary_tree_balance(node);
			if (balance > 1 || balance < -1)
				break;
			new_root = node;
			node = node->parent;
		} while (node);
		if (node)
		{
			left_b = node_height(node->left);
			right_b = node_height(node->right);
			node = left_b > right_b ? node->left : node->right;
			left_b = node_height(node->left);
			right_b = node_height(node->right);
			new_root = left_b > right_b ? node->left : node->right;
		}
		new_root = rebalance_tree(new_root);
	}
	return (new_root);
}
