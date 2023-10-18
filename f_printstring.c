#include "monty.h"

/**
 * print_string - Prints a string from the stack.
 * @stack: Stack head
 * @line_number: Line number
 */
void print_string(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;
	while (current)
	{
		if (current->n > 127 || current->n <= 0)
			break;
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
