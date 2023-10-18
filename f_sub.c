#include "monty.h"

/**
 * subtract - subtracts the top element from the
 * second top element of the stack.
 * @stack: Stack head
 * @counter: Line number
 * Return: No return
 */
void subtract(stack_t **stack, unsigned int counter)
{
	stack_t *current;
	int result, num_nodes;

	current = *stack;
	for (num_nodes = 0; current != NULL; num_nodes++)
		current = current->next;

	if (num_nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	result = current->next->n - current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}
