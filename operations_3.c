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


/**
 * op_mod - mod divides second by top element and replace both with result
 * @stack: double pointer to list node
 * @line_number: line number from monty file
 *
 * Return: no return value
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *first, *second;
	int length, n1, n2, result;

	head = *stack;

	length = get_length(head);

	if (length < 2)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
		a[2] = "mod_stack_to_short";
		return;
	}

	first = head;
	second = first->next;

	n1 = first->n;
	n2 = second->n;

	if (n1 == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		a[2] = "mod_divide_by_0";
		return;
	}

	result = n2 % n1;
	second->n = result;

	op_pop(stack, line_number);
}

