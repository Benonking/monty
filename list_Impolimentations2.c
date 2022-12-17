#include "lists.h"
/**
 * insert_node - insert node at given index
 * @tmp: ptr to nth position node in doubly linked list
 * @n: node data
 * Return: address of inserted node
 */
stack_t *insert_node(stack_t *tmp, int n)
{
	stack_t *new;

	new = malloc(sizeof(struct stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = tmp;
	new->prev = tmp->prev;
	tmp->prev->next = new;
	tmp->prev = new;
	return (new);
}

/**
 * insert_dnodeint_at_index - insert node at index
 * @h: point to head of list
 * @idx: index
 * @n: node data
 * Return: address of new node or NULL if fail
 */

stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n)
{
	stack_t *tmp;

	/* insert at beginning if empty or existing linked list */
	if (idx == 0)
		return (add_dnodeint(h, n));
	if (!h)
		return (NULL);

	/* insert in the middle of list */
	tmp = *h;
	while ((idx != 0) && (tmp->next))
	{
		idx -= 1;
		tmp = tmp->next;
		if (idx == 0)
			return (insert_node(tmp, n));
	}

	/* insert at the end of list if idx is one after last node */
	if (idx == 1)
		return (add_dnodeint_end(h, n));
	return (NULL);
}

