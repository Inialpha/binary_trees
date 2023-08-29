#include "binary_trees.h"


/**
 * _depth - measures the depth of a node in a binary tree.
 *@tree: pointer to the node to measure the depth.
 * Return: if tree is NULL, function must return 0.
 */
size_t _depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (1 + _depth(tree->parent));
}


/**
 * *binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: is a pointer to the first node
 * @second: is a pointer to the second node
 * Return: return a pointer to the lowest common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t left, right;
	const binary_tree_t *temp;

	if (!first || !second)
		return (NULL);

	left = _depth(first);
	right = _depth(second);

	if (left > right)
	{
		temp = first;
		first = second;
		second = temp;
	}

	temp = second;
	while (first)
	{
		second = temp;
		while (second)
		{
			if (first == second->parent)
				return ((binary_tree_t *)first);
			second = second->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
