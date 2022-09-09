#include "monty.h"

/**
 * push - adds a new node at the top of the top
 * @top: pointer to the top node of the stack
 *
 * @line_number: line number of input file
 *
 * Return: void
 */
void push(stack_t **top, unsigned int line_number)
{
	stack_t *new;
	char *val;

	val = strtok(NULL, " \r\t\n");
	if (val == NULL || isNumber(val) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_mem();
		exit(EXIT_FAILURE);
	}

	new->n = atoi(val);
	new->next = NULL;
	new->prev = NULL;

	if (*top == NULL) /*no node in the list */
	{
		*top = new;
	}
	else
	{
		new->next = *top;
		(*top)->prev = new;
		*top = new;
	}
}

/**
 * pall - prints all the data values in each node of the stack.
 * @top: pointer to the top of the stack
 *
 * @line_number: line number of the input file
 * Return: void
 */

void pall(stack_t **top, unsigned int line_number)
{
	stack_t *ptr = NULL;

	(void)(line_number);

	ptr = *top;
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
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_mem();
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
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_mem();
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
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	ptr = (*top)->next;
	temp = (*top)->n;
	(*top)->n = ptr->n;
	ptr->n = temp;
}
