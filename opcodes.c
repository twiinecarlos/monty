#include "monty.h"

/**
 * op_push - pushes an element onto the stack
 * @stack: pointer to the top of the stack
 * @line_number: current line number in the bytecode file
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	char *arg = bus.push_arg;
	int i = 0;

	if (!arg || (arg[0] == '-' && !arg[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (arg[0] == '-')
		i = 1;
	for (; arg[i]; i++)
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = atoi(arg);
	node->prev = NULL;
	node->next = *stack;
	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}

/**
 * op_pall - prints all values on the stack from top to bottom
 * @stack: pointer to the top of the stack
 * @line_number: current line number (unused)
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
