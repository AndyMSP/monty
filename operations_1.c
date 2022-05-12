#include "monty.h"


/**
 * op_push - adds node at head of doubly linked list
 * @stack: double pointer to list node
 * @line_number: line number from monty file
 *
 * Return: no return value
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *new;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		exit(0);
	}

	new->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}

	n = get_int();

	new->n = n;
	*stack = new;
	new->prev = NULL;
}



/**
 * op_pall - prints entire stack
 * @stack: double pointer to list node
 * @line_number: line number from monty file
 *
 * Return: no return value
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void)line_number;

	node = *stack;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}





/**
 * op_bad - handles invalid monty command
 * @stack: double pointer to list node
 * @line_number: line number from monty file
 *
 * Return: no return value
 */
void op_bad(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, a[0]);
	a[2] = "bad command";
}
