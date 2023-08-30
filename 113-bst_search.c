#include "binary_trees.h"

/**
 * bst_search - search a binary tree
 * @tree: tree to be search
 * @value: value to search for
 * Return: pointer to node containing value
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);


	if (tree->n == value)
		return ((bst_t *)tree);

	if (tree->n > value)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));

	return (NULL);
}
