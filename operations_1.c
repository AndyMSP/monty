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

	n = get_int();

	if (a[2] != NULL)
	{
		if (strcmp(a[2], "not_int") == 0)
		{
			fprintf(stderr, "L%i: usage: push integer\n", line_number);
			return;
		}

		if (strcmp(a[2], "test malloc failed\n") == 0)
			return;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		a[2] = "new malloc failed\n";
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}

	new->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}

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
	a[2] = "bad_instruction";
}


/**
 * op_pint - prints value at the top of the stack, followed by a new line
 * @stack: double pointer to list node
 * @line_number: line number from monty file
 *
 * Return: no return value
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;

	if ((head) == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		a[2] = "pint_stack_empty";
		return;
	}

	printf("%i\n", head->n);

}

/**
 * op_pop - remove top element from stack
 * @stack: double pointer to list node
 * @line_number: line number from monty file
 *
 * Return: no return value
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *del;

	head = *stack;

	if ((head) == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		a[2] = "pop_stack_empty";
		return;
	}
	else if (head->next == NULL)
	{
		del = head;
		head = NULL;
		free(del);
	}
	else
	{
		del = head;
		head = del->next;
		free(del);
	}

	*stack = head;
}
