#include "monty.h"

/**
 * op_mul - multiplies first and second element and replace both with result
 * @stack: double pointer to list node
 * @line_number: line number from monty file
 *
 * Return: no return value
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *first, *second;
	int length, n1, n2, result;

	head = *stack;

	length = get_length(head);

	if (length < 2)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
		a[2] = "mul_stack_to_short";
		return;
	}

	first = head;
	second = first->next;

	n1 = first->n;
	n2 = second->n;

	result = n2 * n1;
	second->n = result;

	op_pop(stack, line_number);
}
