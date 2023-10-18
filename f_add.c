#include "monty.h"

/**
 * customAdd - Adds the top two elements of the stack.
 * @head: Pointer to the stack head.
 * @lineNumber: Line number where the operation is executed.
 * Return: No return value.
 */
void customAdd(stack_t **head, unsigned int lineNumber)
{
	stack_t *current;
	int count = 0, result;

	current = *head;
	while (current)
	{
		current = current->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineNumber);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	result = current->n + current->next->n;
	current->next->n = result;
	*head = current->next;
	free(current);
}

/**
 * pushToStack - Add a new node to the stack.
 * @head: Pointer to the head of the stack.
 * @value: The value to be added to the new node.
 * Return: No return value.
 */
void pushToStack(stack_t **head, int value)
{
	stack_t *newNode, *currentNode;

	currentNode = *head;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (currentNode)
	{
		currentNode->prev = newNode;
	}
	newNode->n = value;
	newNode->next = *head;
	newNode->prev = NULL;
	*head = newNode;
}
