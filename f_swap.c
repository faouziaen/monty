#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: Stack head
 * @counter: Line number
 */
void swap(stack_t **stack, unsigned int counter)
{
	stack_t *current;
	int length = 0, temp;

	current = *stack;
	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}
