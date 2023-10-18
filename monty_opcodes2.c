#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number of the Monty bytecode.
  */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - Does nothing; a placeholder function.
 * @stack: A pointer to the stack.
 * @line_number: The current line number of the Monty bytecode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * isNumeric - Checks if a string represents a numeric value.
 * @str: A pointer to the string to be checked.
 *  Return: true if the string is numeric, false otherwise.
 */
bool isNumeric(const char *str)
{
	int i;

	if (str == NULL || *str == '\0')
	{
		return (false);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (false);
		}
	}
	return (true);
}
