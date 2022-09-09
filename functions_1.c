#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 *
 * @top: pointer to the first element of the stack
 * @line_number: line number of input file
 * Return: void
 */
void add(stack_t **top, unsigned int line_number)
{
	int sum = 0;
	stack_t *ptr;

	if (stack_len(top) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	ptr = (*top)->next;
	sum = ((*top)->n) + (ptr->n);
	ptr->n = sum;
	pop(top, line_number);
}

/**
 * nop - does nothing
 * @line_number: line number of input file
 * @top: pointer to the top element in the stack.
 * Return: void
 */
void nop(stack_t **top, unsigned int line_number)
{
	(void)(*top);
	(void)(line_number);
}

/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @top: pointer to the first element of the stack
 * @line_number: line number of input file
 *
 * Return: void
 */
void sub(stack_t **top, unsigned int line_number)
{
	int sub = 0;
	stack_t *ptr;

	if (stack_len(top) < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	ptr = (*top)->next;
	sub = (ptr->n) - ((*top)->n);
	ptr->n = sub;
	pop(top, line_number);
}

/**
 * divi - divides the second top element of the stack
 * by the top element of the stack.
 * @top: pointer to the first element of the stack
 * @line_number: line number of the input file
 *
 * Return: void
 */
void divi(stack_t **top, unsigned int line_number)
{
	int div = 1;
	stack_t *ptr;

	if (stack_len(top) < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	ptr = (*top)->next;
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	ptr = (*top)->next;
	div = (ptr->n) / (*top)->n;
	ptr->n = div;
	pop(top, line_number);
}

/**
 * stack_len - finds number of elements in a slack
 * @top: pointer to the first element of the stack
 *
 * Return: number of elements
 */
size_t stack_len(stack_t **top)
{
	size_t count = 0;
	stack_t *ptr;

	ptr = *top;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
