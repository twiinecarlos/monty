#include "monty.h"

void execute(char *opcode, stack_t **stack, unsigned int line)
{
	if (strcmp(opcode, "push") == 0)
		push(stack, line, value);
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line, opcode);
		exit(EXIT_FAILURE);
	}
}
