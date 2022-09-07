#include "monty.h"

/**
 * push - adds a new node at the top of the top
 * @last: pointer to the last node of the linked list
 * @data: data to be stored
 * @line_number: line number of input file
 *
 * Return: void 
 */
void push(stack_t **top, unsigned int line_number)
{
	stack_t *new;
	int num, i;
	char *val;

	val = strtok(NULL, " \r\t\n");
	new = malloc(sizeof(stack_t));

	for (i = 0; val[i] != '\0'; i++)
	{
		if (val[i] = '-' && i == 0)
			continue;
		if (isdigit(val[i]))
			continue;
		else
		{
			fprintf(stderr, "L%d: usage: push integer", line_number);
		}
	}

	if (new == NULL)
		return;

	num = atoi(val)
	new->n = num;
	new->next = NULL;
	new->prev = NULL;

	if (*top == NULL) /*no node in the list */
	{
		*top = new;
		return;
	}
	new->next = *top;
	(*top)->prev = new;
	*top = new;
}

/**
 * pall - prints all the data values in each node of the stack.
 * @top: pointer to the top of the stack
 * @last: pointer to the last node in the stack.
 *
 * Return: void 
 */

void pall(stack_t **top, unsigned int line_number)
{
	void (line_number);
	stack_t *ptr;

	ptr = *top;
	if (*top == NULL) /* if stack is empty, print nothing */
		return;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - prints the element at the top of the stack
 * @top: top data structure containing all elements
 * @line_number: current line being read in input file
 * Return: nothing
 */

void pint(stack_t **top, unsigned int line_number)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, top empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}

/**
 * pop - pops an elements from the top
 * @top: doubly linked list top
 * @line_number: line number of input file
 * Return: nothing
 */

void pop(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	ptr = *top;
	if (*top == NULL) /* empty stack */
	{
		fprintf(stderr, "L%u: can't pop an empty top\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (ptr->next == NULL) /* only element in the stack */
	{
		free(*top);
		*top = ptr = NULL;
		return;
	}
	*top = ptr->next;
	(*top)->prev = NULL;
	free(ptr);
	ptr = NULL;
}

/**
 * swap - swaps two elements at the top of the top
 * @top: doubly linked list top
 * @line_number: line number of file being printed
 * Return: nothing
 */

void swap(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;
	int temp;

	if (stack_len(top) < 2)
	{
		fprintf(stderr, "L%u: can't swap, top too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = (*top)->next;
	temp = (*top)->n;
	(*top)->n = ptr->n;
	ptr->n = temp;
}
