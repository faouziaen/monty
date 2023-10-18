#include "monty.h"

/**
 * rot_left - Rotates the stack to the top.
 * @stack: Stack head
 * @counter: Line number
 */
void rot_left(stack_t **stack,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *stack, *new_head;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	new_head = (*stack)->next;
	new_head->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = new_head;
}

/**
 * rot_right - Rotates the stack to the bottom.
 * @stack: Stack head
 * @counter: Line number
  */
void rot_right(stack_t **stack, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy;

	copy = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
