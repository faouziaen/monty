#include "monty.h"

/**
 * printStack - Prints the elements of the stack.
 * @stack: Stack head
 * @line_number: Line number (not used)
 * Return: No return
 */
void printStack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
