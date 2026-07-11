#include "monty.h"

/**
 * execute - executes opcode
 * @opcode: operation code
 * @arg: argument for opcode
 * @stack: pointer to stack
 * @line: line number
 */
void execute(char *opcode, char *arg, stack_t **stack, unsigned int line)
{
	if (strcmp(opcode, "push") == 0)
		push(stack, line, arg);
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line);
	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line);
	else if (strcmp(opcode, "div") == 0)
		div_op(stack, line);
	else if (strcmp(opcode, "mul") == 0)
		mul(stack, line);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line, opcode);
		exit(EXIT_FAILURE);
	}
}
