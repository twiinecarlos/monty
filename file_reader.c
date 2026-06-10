#include "monty.h"

/**
 * read_file - reads monty bytecode file
 * @file: file pointer
 * @stack: stack pointer
 */
void read_file(FILE *file, stack_t **stack)
{
	char line[1024];
	unsigned int line_number = 0;

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		execute_line(line, stack, line_number);
	}
}
