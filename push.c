#include "monty.h"

int is_integer(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	if (str[0] == '-' || str[0] == '+')
		i++;

	if (str[i] == '\0')
		return (0);

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;

	if (!is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
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
