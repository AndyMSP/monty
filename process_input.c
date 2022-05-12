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
	a = malloc(sizeof(a) * 2);

	a[0] = strtok(line, " \t\n");
	a[1] = strtok(NULL, " \t\n");

	return (a);
}


/**
 * get_int - get int from a[1] and validate it
 *
 * Return: 0 if is int and -1 if not
 */
int get_int()
{
	char *test;
	int val;

	test = malloc(sizeof(a[1]));

	val = atoi(a[1]);

	sprintf(test, "%i", val);

	if (strcmp(test, a[1]) == 0)
		return (val);
	else
		a[1][0] = '!';

	return (0);
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
