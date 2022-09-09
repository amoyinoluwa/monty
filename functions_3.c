#include "monty.h"

/**
 * rotl -  rotates the stack to the top
 * @top: pointer to the top of the stack
 * @line_number: line number of the current instruction
 *
 * Return: void 
 */
void rotl(stack_t **top, unsigned int line_number)
{
    stack_t *ptr, *curr;
    int temp;

    (void)line_number;
    curr = ptr = *top;
    if (curr == NULL)
        return;
    while(curr->next != NULL)
    {
        curr = curr->next;
        temp = ptr->n;
        ptr->n = curr->n;
        curr->n = temp;
        ptr = curr;
    }
}
