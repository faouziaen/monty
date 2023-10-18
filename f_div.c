#include "monty.h"

/**
 * divideElements - Divides the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number.
  */
void divideElements(stack_t **stack, unsigned int line_number)
{
	stack_t *currentNode;
	int len = 0, result;

	currentNode = *stack;
	while (currentNode)
	{
		currentNode = currentNode->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	currentNode = *stack;
	if (currentNode->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	result = currentNode->next->n / currentNode->n;
	currentNode->next->n = result;
	*stack = currentNode->next;
	free(currentNode);
}
