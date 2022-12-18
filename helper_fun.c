#include "monty.h"

/**
 * rotl - rotate so top of stack becomes last one, second becomes first one
 * @h: node to be rotated
 * @line_number: node number
 */
void _rotl(stack_t **h, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;

	if ((*h)->next != NULL)
	{
		tmp = *h;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*h)->prev = tmp;
		tmp->next = *h;
		(*h)->next->prev = NULL;
		*h = (*h)->next;
		tmp->next->next = NULL;
	}
}

/**
 * _rotr - rotates the list right
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner1, *runner2;
	int temp1, temp2;

	if (*stack == NULL)
		return;

	runner1 = *stack;
	runner2 = *stack;
	while (runner1->next)
		runner1 = runner1->next;
	while (runner2)
	{
		if (runner2->prev == NULL)
		{
			temp1 = runner2->n;
			runner2->n = runner1->n;
		}
		else
		{
			temp2 = runner2->n;
			runner2->n = temp1;
			temp1 = temp2;
		}
		runner2 = runner2->next;

	}
}
/**
 * swap - swap locations of previous stack with the top stack
 * @h: node to be swapped
 * @line_number: node number
 */
void _swap(stack_t **h, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*h == NULL || (*h)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*h)->next;
	if (tmp->next != NULL)
	{
		(*h)->next = tmp->next;
		(*h)->next->prev = *h;

	}
	else
	{
		tmp->prev->prev = tmp;
		tmp->prev->next = NULL;
	}
	tmp->prev = NULL;
	tmp->next = *h;
	(*h) = tmp;
}
