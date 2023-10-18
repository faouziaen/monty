#include "monty.h"

/**
 * free_stack - Frees a doubly linked list.
 * @stack: Head of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	current = stack;
	while (current)
	{
		stack_t *temp = current;

		current = current->next;
		free(temp);
	}
}
