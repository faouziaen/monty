#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void customAdd(stack_t **head, unsigned int lineNumber);
void pushToStack(stack_t **head, int value);
void pop_top(stack_t **stack, unsigned int line_number);
void divideElements(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void multiplyStack(stack_t **stack, unsigned int line_number);
void modStackTop(stack_t **stack, unsigned int line_number);
void doNothing(stack_t **stack, unsigned int line_number);
void printStack(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void printCharFromStack(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);
void push_node(stack_t **stack, unsigned int line_number);
void set_queue_mode(stack_t **stack, unsigned int line_number);
void add_to_queue(stack_t **stack, int n);
void rot_left(stack_t **stack,  __attribute__((unused)) unsigned int counter);
void rot_right(stack_t **stack, __attribute__((unused)) unsigned int counter);
void switch_to_stack(stack_t **stack, unsigned int count);
void subtract(stack_t **stack, unsigned int counter);
void swap(stack_t **stack, unsigned int counter);
int process(char *content, stack_t **stack, unsigned int counter, FILE *file);

#endif
