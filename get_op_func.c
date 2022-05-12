#include "monty.h"

/**
 * get_op_func - return pointer to appropriate operation function
 *
 * Return: pointer to appropriate function
 */
void (*get_op_func())(stack_t **stack, unsigned int line_number)
{
	int i, num_ops;
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop}
/*
 *		{"swap", op_swap},
 *		{"add", op_add},
 *		{"nop", op_nope}
*/
	};


	num_ops = sizeof(ops) / sizeof(ops[0]);

	for (i = 0; i < num_ops; i++)
	{
		if (strcmp(a[0], ops[i].opcode) == 0)
			return (ops[i].f);
	}

	return (op_bad);
}
