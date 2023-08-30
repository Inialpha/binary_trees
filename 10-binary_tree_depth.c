#include "binary_trees.h"
/**
 * binary_tree_depth - finds the depth of a node
 * @tree: pointer to node to measure the depth
 * Return: depth of pointer if node is a root
 * and 0 if tree is null
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
	{
		return (0);
	}

	if (!tree->parent)
	{
		return (0);
	}

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
