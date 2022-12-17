#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list reperesentation of a stack (or Queue
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack,queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its nfunction
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


stack_t *add_dnodeint_end(dlistint_t **head, const int n);
void free_dlistint(stack_t *head);
stack_t *add_dnodeint(dlistint_t **head, const int n);
stack_t *insert_node(stack_t *tmp, int n);
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
