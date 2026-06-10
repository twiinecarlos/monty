#include "monty.h"

char *push_arg = NULL;

/**
 * main - entry point for the monty interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode;
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}
	};
	int i, found;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;

		/* strip newline */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		opcode = strtok(line, " \t");

		/* skip empty lines and comments */
		if (!opcode || opcode[0] == '#')
			continue;

		/* save argument for push */
		push_arg = strtok(NULL, " \t");

		found = 0;
		for (i = 0; instructions[i].opcode; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				found = 1;
				break;
			}
		}

		if (!found)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free(line);
			fclose(fp);
			/* free stack */
			while (stack)
			{
				stack_t *tmp = stack->next;
				free(stack);
				stack = tmp;
			}
			exit(EXIT_FAILURE);
		}
	}

	free(line);
	fclose(fp);
	while (stack)
	{
		stack_t *tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	return (EXIT_SUCCESS);
}
