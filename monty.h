#ifndef MONTY_H
#define MONTY_H

/*header files to include*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*global variable declaration*/
extern char **a;

/*data structure definitions*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*typedef for function pointer*/
typedef void (operation)(stack_t **stack, unsigned int line_number);


/*custom function prototypes*/
char **reduce_line(char *line);
void (*get_op_func())(stack_t **stack, unsigned int line_number);
int get_int();
void free_list(stack_t *head);

/*operation function prototypes*/
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_bad(stack_t **stack, unsigned int line_number);

#endif
