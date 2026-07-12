#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;

	while (temp)
	{
		if (temp->n == 0 || temp->n < 0 || temp->n > 127)
			break;

		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}
