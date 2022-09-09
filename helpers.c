#include "monty.h"

/**
 * free_mem - frees up allocated memory
 * @head: head of linked list
 * Return: nothing
 */

void free_mem(void)
{
	stack_t *node = NULL;

	if (file.buffer)
	{
		while (file.buffer != NULL)
		{
			node = file.buffer->next;
			free(file.buffer);
			file.buffer = node;
		}
	}
	free(file.chars);
	fclose(file.fp);
}

/**
 * isNumber - checks if string token is an integer
 * @token: string input
 * Return: 1 or 0
 */

int isNumber(char* token)
{
	int i;

	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] == '-' && i == 0)
			i++;
                if (token[i] < 48 || token[i] > 57)
			return (0);
	}
	return (1);
}
