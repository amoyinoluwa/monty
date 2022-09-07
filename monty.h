#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

/* Standard Library */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******** NODE STRCUT **********/
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/********** INSRUCTION STRUCT ****************/
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* Function prototypes */
void push(stack_t **top, stack_t **last, int data);
void pint(stack_t **top, unsigned int line_number);
void pop(stack_t **top, unsigned int line_number);
void swap(stack_t **top, unsigned int line_number);
size_t stack_len(stack_t **top);
void add(stack_t **top, unsigned int line);
void sub(stack_t **top, unsigned int line_number);
void nop();
void divi(stack_t **top, unsigned int line_number);

/* please endeavor to use variable top to reference the top pointer, thanks */
#endif
int (*get_function(char*))(stack_t, unsigned int);

#endif

