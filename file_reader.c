#include "monty.h"

void read_file(FILE *file, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		opcode = strtok(line, " \t\n");
		value = strtok(NULL, " \t\n");

		if (!opcode)
			continue;

		execute(opcode, stack, line_number);
	}

	free(line);
}
