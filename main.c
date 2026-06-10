
#include "monty.h"

char *arg = NULL;

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char line[1024];
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_number++;

		opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t\n");
			push(&stack, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
				line_number, opcode);
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	free_stack(stack);
	fclose(file);

	return (0);
}
