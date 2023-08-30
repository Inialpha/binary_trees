#include "binary_trees.h"

/**
 * bst_insert - insert in a bst
 * @tree: root
 * @value: value
 * Return: new node
 */

bst_t *bst_insert(bst_t **tree, int value)
{

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	if ((*tree)->n > value)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		return (bst_insert(&(*tree)->left, value));
	}
	if ((*tree)->n < value)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		return (bst_insert(&(*tree)->right, value));
	}
	return (NULL);
}

