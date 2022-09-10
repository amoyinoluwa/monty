#include "monty.h"

/**
 * mul -  multiplies the second top element
 * of the stack with the top element of the stack.
 * @top: pointer to the first element of the stack
 * @line_number: line number of input file
 * Return: void
 */
void mul(stack_t **top, unsigned int line_number)
{
	int mul;
	stack_t *ptr;

	if (stack_len(top) < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	ptr = (*top)->next;
	mul = ((*top)->n) * (ptr->n);
	ptr->n = mul;
	pop(top, line_number);
}

/**
 * mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * of the stack with the top element of the stack.
 * @top: pointer to the first element of the stack
 * @line_number: line number of input file
 * Return: void
 */
void mod(stack_t **top, unsigned int line_number)
{
	int mod;
	stack_t *ptr;

	if (stack_len(top) < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
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
	mod = (ptr->n) % ((*top)->n);
	ptr->n = mod;
	pop(top, line_number);
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @top: pointer to the top of the stack
 * @line_number: line number of the input file
 *
 * Return: void
 */

void pchar(stack_t **top, unsigned int line_number)
{
	 int ascii;

	 if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	ascii = (*top)->n;
	if (ascii < 0 || ascii > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	_putchar(ascii);
	_putchar('\n');
}

/**
 * pstr: prints the string starting at the top of the stack.
 * @top: pointer to the top of the stack.
 * @line_number: line number of the input file
 * 
 * Return: void
 */
void pstr(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;
	int ascii;

	(void)line_number;
	ptr = *top;
	if (ptr == NULL)
		_putchar('\n');
	while (ptr)
	{
		ascii = ptr->n;
		if (ascii == 0 || (ascii < 0 && ascii > 255))
		{
			_putchar('\n');
			return;
		}
		_putchar(ascii);
		ptr = ptr->next;
	}
}

/**
 * _putchar - prints a character to stdout
 * @c: character to print
 *
 * Return: int
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}
