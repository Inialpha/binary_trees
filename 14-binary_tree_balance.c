#include "binary_trees.h"


/**
 * get_height - gets tree heght
 * @tree: bt
 * Return: height
 */

int get_height(binary_tree_t *tree)
{
	int left, right;

	left = 1;
	right = 1;
	if (!tree)
		return (0);
	if (tree->left)
		left += get_height(tree->left);
	if (tree->right)
		right += get_height(tree->right);

	if (left > right)
		return (left);
	else
		return (right);
}


/**
 * binary_tree_balance - balance a bt
 * @tree: bt
 * Return: the balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	left = get_height(tree->left);

	right = get_height(tree->right);

	return (left - right);
}
