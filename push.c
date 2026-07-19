#include "monty.h"

/**
 * is_integer - checks if string is integer
 * @str: input string
 *
 * Return: 1 if valid, 0 otherwise
 */
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

/**
 * insert_node - inserts a new node at the head (stack mode) or
 * tail (queue mode) of the list, based on the global mode variable
 * @stack: stack pointer
 * @new_node: the node to insert
 */
void insert_node(stack_t **stack, stack_t *new_node)
{
	stack_t *temp;

	if (mode == 's')
	{
		new_node->next = *stack;
		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else
	{
		if (*stack == NULL)
		{
			*stack = new_node;
			return;
		}
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
}

/**
 * push - pushes value to stack
 * @stack: stack pointer
 * @line_number: line number
 * @arg: value
 */
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
	new_node->next = NULL;
	insert_node(stack, new_node);
}
