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
