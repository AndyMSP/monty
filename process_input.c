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
/*
int get_int()
{
	char *test;
	int val;

	test = malloc(sizeof(a[1]));
	if (test == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		a[2] = "test malloc failed";
	}

	val = atoi(a[1]);

	sprintf(test, "%i", val);

	if (strcmp(test, a[1]) == 0)
	{
		free(test);
		return (val);
	}
	else
		a[2] = "not_int";

	free(test);

	return (0);
}
*/

int get_int()
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
		if((a[1][i] < 48 || a[1][i] > 57) && a[1][i] != '-')
		{
			printf("not int check failed\n");
			a[2] = "not_int";
			break;
		}
		i++;
	}

	val = atoi(a[1]);

	return (val);
}


/**
 * main - test reduce_line function
 *
 * Return: Always 0
 */
/*
int main(void)
{
	char str[] = "t \n", **a;

	a = reduce_line(str);

	printf("a[0] = \"%s\"\n", a[0]);
	printf("a[1] = \"%s\"\n", a[1]);

	free(a);

	return (0);
}
*/
