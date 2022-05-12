/*
 * This program demonstrates the following:
 *	What is FILE *stream
 *	fopen use
 *	getline: nread meaning, len meaning
 *	stderr changing color after installing stderred
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	(void)argc;

	stream = fopen(argv[1], "r");

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		printf("len = %li, nread = %li\n", len, nread);
		printf("%s\n", line);		
	}

	fprintf(stderr, "This is stderr\n");
	fprintf(stdout, "This is stdout\n");

	free(line);
	fclose(stream);

	return (0);
}
