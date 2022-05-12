#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments including program call
 * @argv: double pointer to char from command line
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

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");

	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	a = malloc(sizeof(a) * 3);
	if (a == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(stream);
		exit(EXIT_FAILURE);
	}

	a[2] = NULL;

	i = 0;
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		i++;
		a = reduce_line(line);
		if (a[0] == NULL)
			continue;
		op = get_op_func();
		op(&head, i);
		if (a[2] != NULL)
			break;
	}

	if (errno == ENOMEM)
	{
		fprintf(stderr, "Error: malloc failed\n");
		a[2] = "getline malloc failed";
	}

	free(line);
	free_list(head);
	fclose(stream);

	if (a[2] != NULL)
	{
		free(a);
		exit(EXIT_FAILURE);
	}

	free(a);

	return (0);
}
