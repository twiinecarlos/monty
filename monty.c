#include "monty.h"

bus_t bus = {NULL, NULL, NULL, NULL};

/**
 * free_stack - frees all nodes in the stack
 * @stack: pointer to the top node
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

/**
 * run_line - dispatches a single opcode line
 * @stack: pointer to stack pointer
 * @line_number: current line number
 */
void run_line(stack_t **stack, unsigned int line_number)
{
	char *opcode;
	int i, found;
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}
	};

	opcode = strtok(bus.line, " \t");
	if (!opcode || opcode[0] == '#')
		return;

	bus.push_arg = strtok(NULL, " \t");
	found = 0;
	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			found = 1;
			break;
		}
	}
	if (!found)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free_stack(*stack);
		free(bus.line);
		fclose(bus.fp);
		exit(EXIT_FAILURE);
	}
}

/**
 * run_file - reads and executes every line in the bytecode file
 */
void run_file(void)
{
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while ((read = getline(&bus.line, &len, bus.fp)) != -1)
	{
		line_number++;
		if (bus.line[read - 1] == '\n')
			bus.line[read - 1] = '\0';
		run_line(&stack, line_number);
	}
	free_stack(stack);
	free(bus.line);
	fclose(bus.fp);
}

/**
 * main - entry point for the monty interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	bus.filename = argv[1];
	bus.fp = fopen(bus.filename, "r");
	if (!bus.fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", bus.filename);
		exit(EXIT_FAILURE);
	}
	run_file();
	return (EXIT_SUCCESS);
}
