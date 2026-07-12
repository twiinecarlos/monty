#define _GNU_SOURCE
#include "monty.h"

/**
 * read_file - reads bytecode file
 * @file: file pointer
 * @stack: stack pointer
 */
void read_file(FILE *file, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	char *opcode;
	char *arg;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;

		opcode = strtok(line, " \t\n");

		if (!opcode)
			continue;

		if (opcode[0] == '#')
			continue;

		arg = strtok(NULL, " \t\n");

		execute(opcode, arg, stack, line_number);
	}

	free(line);
}
