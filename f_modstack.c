#include "monty.h"

/**
 * modStackTop - Computes the remainder of the division
 * of the second top element of the stack by the top element.
 * @stack: Stack head
 * @line_number: Line number
 */
void modStackTop(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	result = current->next->n % current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}
