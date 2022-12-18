#include "monty.h"

/**
 * free_stack - free doubly linked list
 * @head: point to head of list
 * Return: 0 on sucess
 */

void free_stack(stack_t **head)
{
	if (!head)
		return;
	while (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}

/**
 * add_stacknode_beg - add new node at the begining of doubly linked list
 * @head: point to head of list
 * @n:data to be added
 * Return: address of new added element or NULL on fail
 */

int add_stacknode_beg(stack_t **head, int n)
{
	stack_t *new;

	if (!head)
		return (-1);
	new = malloc(sizeof(stack_t));
	if (!new)
		return (-1);
	new->n = n;

	if ((*head) == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	return (0);
}

/**
 * delete_end_node - deletes node at end of doubly linked list
 * @h: pointer to head of doubly linked list
 */
void delete_end_node(stack_t **h)
{
	stack_t *del = NULL;

	/* account for only one node in list */
	del = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(del);
	}
	else /* else delete front, and link correctly */
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(del);
	}
}
