#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 0 or 1
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue *head, *tail;
	int flag = 0;

	if (!tree)
		return (0);

	head = tail = createnode((binary_tree_t *)tree);

	if (!head)
		exit(1);
	while (head)
	{
		if (head->node->left)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			add_queue(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			add_queue(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);

	}
	return (1);
}

/**
 * createnode - creates a node
 * @node: binary_tree node
 * Return: node
 */
queue *createnode(binary_tree_t *node)
{
	queue *new = malloc(sizeof(queue));

	if (!new)
		return (NULL);
	new->node = node;
	new->next = NULL;

	return (new);
}


/**
 * free_queue - frees the queue
 * @head: pointer to the first node
 */

void free_queue(queue *head)
{
	queue *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}


/**
 * add_queue - adds to queue
 * @node: node to be added
 * @head: heade of queue
 * @tail: tail of queue
 */

void add_queue(binary_tree_t *node, queue *head, queue **tail)
{
	queue *new = createnode(node);

	if (!new)
	{
		free_queue(head);
		exit(89);
	}
	if (*tail)
	{
		(*tail)->next = new;
		*tail = new;
	}
	else
		*tail = new;
}

/**
 * pop - pop queue
 * @head: head of queue
 */

void pop(queue **head)
{
	queue *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}
