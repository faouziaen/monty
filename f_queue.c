#include "monty.h"

/**
 * set_queue_mode - Set the queue mode.
 * @stack: Stack head
 * @line_number: Line number
 */
void set_queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	bus.lifi = 0;
}

/**
 * add_to_queue - Add a node to the queue (at the tail of the stack).
 * @stack: Stack head
 * @n: New value
 * Return: No return
 */
void add_to_queue(stack_t **stack, int n)
{
	stack_t *new_node, *tail;

	tail = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (tail)
	{
		while (tail->next)
			tail = tail->next;
	}
	if (!tail)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tail->next = new_node;
		new_node->prev = tail;
	}
}
