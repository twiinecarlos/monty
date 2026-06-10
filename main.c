#include "monty.h"

char *arg = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: arguments
 *
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_file(file, &stack);

	fclose(file);
	free_stack(stack);

	return (0);
}
