#include "binary_trees.h"

/**
 * binary_tree_rotate_right - binary_tree_rotate_right
 * @tree: the tree to rotate
 * Return: new root
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *child;

	if (!tree || !tree->left)
		return (NULL);

	child = tree->left;
	child->parent = tree->parent;
	tree->parent = child;
	tree->left = child->right;
	if (child->right)
		child->right->parent = tree;
	child->right = tree;
	return (child);
}
