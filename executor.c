#include "monty.h"

/**
 * execute_line - runs opcode
 * @line: input line
 * @stack: stack
 * @line_number: line number
 */
void execute_line(char *line, stack_t **stack,
	unsigned int line_number)
{
	char *opcode;

	opcode = strtok(line, " \t\n");

	if (!opcode || opcode[0] == '#')
		return;

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \t\n");
		push(stack, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
