#include "monty.h"

void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}


void pall(const stack_t *stack)
{
    while (stack)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}


void pint(const stack_t *stack, unsigned int line_number)
{
    if (stack)
        printf("%d\n", stack->n);
    else
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
}


void pop(stack_t **stack, unsigned int line_number)
{
    if (*stack)
    {
        stack_t *temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
    else
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
}


void swap(stack_t **stack, unsigned int line_number)
{
    if (*stack && (*stack)->next)
    {
        int temp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = temp;
    }
    else
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
}


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


void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

bool isNumeric(const char *str) {
    int i;
    
    if (str == NULL || *str == '\0') {
        return (false);
    }

    
for (i = 0; str[i] != '\0'; i++) 
{
        if (str[i] < '0' || str[i] > '9') {
            return (false);
        }
    }

    return (true);
}