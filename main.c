#define _GNU_SOURCE 

#include "monty.h"
#include <stdio.h>

stack_t *stack = NULL;

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 1;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        char *opcode, *arg;
        opcode = strtok(line, " \t\n");
        if (opcode && opcode[0] != '#')  
        {
            arg = strtok(NULL, " \t\n");
            if (strcmp(opcode, "push") == 0)
            {
                if (!arg)
                {
                    fprintf(stderr, "L%u: usage: push integer\n", line_number);
                    free(line);
                    fclose(file);
                    exit(EXIT_FAILURE);
                }
                if (!isNumeric(arg))
                {
                    fprintf(stderr, "L%u: usage: push integer\n", line_number);
                    free(line);
                    fclose(file);
                    exit(EXIT_FAILURE);
                }
                push(&stack, atoi(arg));
            }
            else if (strcmp(opcode, "pall") == 0)
            {
                pall(stack);
            }
            else if (strcmp(opcode, "pint") == 0)
            {
                pint(stack, line_number);
            }
            else if (strcmp(opcode, "pop") == 0)
            {
                pop(&stack, line_number);
            }
            else if (strcmp(opcode, "swap") == 0)
            {
                swap(&stack, line_number);
            }
            else if (strcmp(opcode, "add") == 0)
            {
                add(&stack, line_number);
            }
            else if (strcmp(opcode, "nop") == 0)
            {
                nop(&stack, line_number);
            }
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                free(line);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
        line_number++;
    }

    free(line);
    processMontyFile(file);
    fclose(file);
    return (0);
}