#include "monty.h"

/**
 * is_integer - checks valid integer
 * @str: string
 * Return: 1 or 0
 */
int is_integer(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	if (str[0] == '-')
		i++;

	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}

/**
 * push - pushes node to stack
 * @stack: stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (!is_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(arg);
	new->prev = NULL;
	new->next = *stack;

	if (*stack)
		(*stack)->prev = new;

	*stack = new;
}
