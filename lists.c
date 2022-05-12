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
