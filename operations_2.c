#include "monty.h"

/**
 * op_swap - swap top 2 values of stack
 * @stack: double pointer to list node
 * @line_number: line number from monty file
 *
 * Return: no return value
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *first, *second;
	int length, n1, n2;

	head = *stack;

	length = get_length(head);

	if (length < 2)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		a[2] = "pop_stack_empty";
		return;
	}

	first = head;
	second = first->next;

	n1 = first->n;
	n2 = second->n;

	first->n = n2;
	second->n = n1;

	*stack = head;

}

