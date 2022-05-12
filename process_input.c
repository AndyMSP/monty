#include "monty.h"

/**
 * reduce_line - takes string and returns first two strings delimited by " "
 * @line: pointer to char
 *
 * Return: array of two pointers to char
 *
 ***IMPORTANT - MUST FREE RETURN VARIABLE***
 */
char **reduce_line(char *line)
{
	a[0] = strtok(line, " \t\n");
	a[1] = strtok(NULL, " \t\n");
	a[2] = NULL;

	return (a);
}


/**
 * get_int - get int from a[1] and validate it
 *
 * Return: 0 if is int and -1 if not
 */
int get_int(void)
{
	int i, val = 0;

	if (a[1] == NULL)
	{
		a[2] = "not_int";
		return (-1);
	}

	i = 0;
	while (a[1][i] != 0)
	{
		if ((a[1][i] < 48 || a[1][i] > 57) && a[1][i] != '-')
		{
			a[2] = "not_int";
			break;
		}
		i++;
	}

	val = atoi(a[1]);

	return (val);
}


/**
 * input_check - checks if input is valid
 * @argc: int number of arguments
 * @argv: double pointer to char
 *
 * Return: no return value
 */
FILE *input_check(int argc, char **argv)
{
	FILE *stream;

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

	return (stream);
}
