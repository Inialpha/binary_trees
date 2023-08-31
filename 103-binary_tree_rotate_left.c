#include "binary_trees.h"

/**
 * binary_tree_rotate_left - binary_tree_rotate_left
 * @tree: the tree to rotate
 * Return: new root
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *child;

	if (!tree || !tree->right)
		return (NULL);

	child = tree->right;
	child->parent = tree->parent;
	tree->parent = child;
	tree->right = child->left;
	if (child->left)
		child->left->parent = tree;
	child->left = tree;
	return (child);
}
