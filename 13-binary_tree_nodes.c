#include "binary_trees.h"

/**
 * binary_tree_nodes - measures the size of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the size
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	 size_t left = 0;
	 size_t right = 0;

	if (tree->left)
		left = binary_tree_nodes(tree->left);

	if (tree->right && !tree->left)
		right = binary_tree_nodes(tree->right);
	return ((left + right) + 1);
}
