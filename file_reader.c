#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * read_file - reads bytecode file
 * @file: file pointer
 * @stack: stack pointer
 */
void read_file(FILE *file, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode;
	char *arg;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

		if (!opcode)
			continue;

		execute(opcode, arg, stack, line_number);
	}

	free(line);
}
