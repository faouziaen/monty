#include "monty.h"

/**
 * pop_top - Removes the top element from the stack.
 * @stack: Stack head
 * @line_number: Line number
  */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = top->next;
	free(top);
}
