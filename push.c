#include "monty.h"

extern char *arg;

/**
 * is_integer - checks if string is integer
 * @str: string to check
 *
 * Return: 1 if integer, 0 otherwise
 */
int is_integer(char *str)
{
	int i = 0;

	if (str == NULL)
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
 * push - pushes element onto stack
 * @stack: pointer to stack
 * @line_number: current line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (!is_integer(arg))
	{
		fprintf(stderr,
			"L%d: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
