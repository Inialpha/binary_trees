#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: is a pointer to the first element
 * @size: is the number of element in the array
 * Return: root
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root = NULL;

	if (!array || size == 0)
		return (NULL);


	while (i < size)
	{
		bst_insert(&root, array[i]);
		i++;
	}
	return (root);
}
