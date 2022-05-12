#include "monty.h"


/**
 * op_push - adds node at head of doubly linked list
 * @stack: double pointer to list node
 * @line_number: line number from monty file
 *
 * Return: no return value
 */
void op_push(stack_t **head, unsigned int line_number)
{
	int n;
	stack_t *new;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		exit(0);
	}

	new->next = *head;
	if (*head != NULL)
	{
		(*head)->prev = new;
	}

	n = get_int();

	new->n = n;
	*head = new;
	new->prev = NULL;
}





void op_pall(stack_t **head, unsigned int line_number)
{
	stack_t *node;

	(void)line_number;

	node = *head;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}






void op_bad(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	printf("line %i is bad\n", line_number);
}
