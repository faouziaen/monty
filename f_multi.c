#include "monty.h"

/**
 * multiplyStack - Multiplies the top two elements of the stack.
 * @stack: Stack head
 * @line_number: Line number
 * Return: No return
 */
void multiplyStack(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int len = 0, result;

	current = *stack;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	result = current->next->n * current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}
