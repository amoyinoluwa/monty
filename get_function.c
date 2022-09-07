#include "monty.h"

/**
 * get_function - function handler
 * @input: input string
 * Return: pointer to function
 */

void get_function(char *input, stack_t **s, unsigned int line)
{
	instruction_t instruction[] = {
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"pall", pall},
		{"push", push},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divi},
		{NULL, NULL}
	};
	int i = 0;

	while (instruction[i].opcode)
	{
		if (strcmp(instruction[i].opcode, input) == 0)
		{
			instruction[i].f(s, line);
			break;
		}
		i++;
	}
	if (instruction[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line, input);
		exit(EXIT_FAILURE);
	}
}
