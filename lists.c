#include "monty.h"

/**
 * free_list - free entire doubly linked list
 * @head: pointer to head of list
 *
 * Return: No return value (void)
 */
void free_list(stack_t *head)
{
	stack_t *node, *next;

	if (head == NULL)
		return;

	node = head;

	while (node->next != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}

	free(node);
}


/**
 * get_length - get length of doubly linked list
 * @head: pointer to stack_t list
 *
 * Return: int number of nodes
 */
int get_length(stack_t *head)
{
	int length;
	stack_t *node;

	node = head;

	length = 0;
	while (node != NULL)
	{
		length++;
		node = node->next;
	}

	return (length);
}
