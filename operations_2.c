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
		a[2] = "swap_stack_to_short";
		return;
	}

	first = head;
	second = first->next;

	n1 = first->n;
	n2 = second->n;

	first->n = n2;
	second->n = n1;
}


/**
 * op_add - add top 2 elements and replace top 2 with single sum
 * @stack: double pointer to list node
 * @line_number: line number from monty file
 *
 * Return: no return value
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *first, *second;
	int length, n1, n2, sum;

	head = *stack;

	length = get_length(head);

	if (length < 2)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		a[2] = "add_stack_to_short";
		return;
	}

	first = head;
	second = first->next;

	n1 = first->n;
	n2 = second->n;
	sum = n1 + n2;
	second->n = sum;

	op_pop(stack, line_number);
}


/**
 * op_nop - does nothing
 * @stack: double pointer to list node
 * @line_number: line number from monty file
 *
 * Return: no return value
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	return;
}


/**
 * op_sub - subtract top from second element and replace both with result
 * @stack: double pointer to list node
 * @line_number: line number from monty file
 *
 * Return: no return value
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *first, *second;
	int length, n1, n2, dif;

	head = *stack;

	length = get_length(head);

	if (length < 2)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		a[2] = "sub_stack_to_short";
		return;
	}

	first = head;
	second = first->next;

	n1 = first->n;
	n2 = second->n;
	dif = n1 - n2;
	second->n = dif;

	op_pop(stack, line_number);
}
