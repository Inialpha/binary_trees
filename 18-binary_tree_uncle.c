#include "binary_trees.h"

/**
 * binary_tree_uncle - binary_tree_uncle
 * @node: node
 * Return: uncle or NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;
	binary_tree_t *grand_p;

	if (!node)
		return (NULL);

	parent = node->parent;
	if (parent)
		grand_p = parent->parent;
	else
		return (NULL);
	if (grand_p)
	{
		if (grand_p->left == parent)
			return (grand_p->right);
		else
			return (grand_p->left);
	}
	else
		return (NULL);
}
