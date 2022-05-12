#include "monty.h"

char **a;

/**
 * main - entry point
 * argc: number of arguments including program call
 * argv: double pointer to char from command line
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int i = 0;
	operation *op;
	stack_t *head = NULL;

	(void)argc;

	stream = fopen(argv[1], "r");

	i = 0;
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		i++;
		a = reduce_line(line);
		op = get_op_func();
		op(&head, i);
		free(a);
	}

	free(line);
	free_list(head);
	fclose(stream);

	return (0);
}
