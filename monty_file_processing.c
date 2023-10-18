#include "monty.h"

void processMontyFile(FILE *file)
{
    char *line = NULL;

    unsigned int line_number = 1;
    while (fgets(line, sizeof(line), file))
    {
        char *opcode, *arg;
        opcode = strtok(line, " \t\n");
        if (opcode && opcode[0] != '#') 
        {
            arg = strtok(NULL, " \t\n");
            if (strcmp(opcode, "push") == 0)
            {
                if (!arg || !isNumeric(arg))
                {
                    fprintf(stderr, "L%u: usage: push integer\n", line_number);
                    free(line);
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
}