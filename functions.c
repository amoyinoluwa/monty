#include "monty.h"

/**
 * pint - prints the element at the top of the stack
 * @stack: stack data structure containing all elements
 * @line_number: current line being read in input file
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	else
	{
		printf("%d\n", (*stack)->n);
	}
}

/**
 * pop - pops an elements from the stack
 * @stack: doubly linked list stack
 * @line_number: line number of input file
 * Return: nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node *top;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	node = *stack;

	if (node->prev == NULL)
		free(node);
	else
	{
		top = node->prev;
		top->next = NULL;
		*stack = top;
		free(node);
	}
}
