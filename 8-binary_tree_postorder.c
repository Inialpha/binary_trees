#include "binary_trees.h"

/**
 * binary_tree_postorder - traverses the binary tree
 * @tree: binary tree
 * @func: function to be performed on tree
 * Return: 1 if node is a root, otherwise 0
 * If node is NULL, return 0
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
	{
		return;
	}
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
