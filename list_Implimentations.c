#include "monty.h"

/**
 * add_stacknode_end - add node at end of doubly linked list
 * @head: point to head of list
 * @n: data/ node to be added
 * Return: new element or NULL on fail
 */

stack_t *add_stacknode_end(stack_t **head, const int n)
{
	stack_t *temp;
	stack_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	temp = *head;/*store the head node temporarilty*/
	if ((*head) == NULL)/*make new node head if list is empty*/
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		return (new);
	} /*move to last node*/
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	new->next = NULL;
	new->prev = temp;
	temp->next = new;

	return (new);
}
/**
 * free_stack - free doubly linked list
 * @head: point to head of list
 * Return: 0 on sucess
 */

void free_stack(stack_t *head)
{
	if (!head)
		return;
	while (head && head->next)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}

/**
 * add_stacknode_beg - add new node at the begining of doubly linked list
 * @head: point to head of list
 * @n:data to be added
 * Return: address of new added element or NULL on fail
 */

stack_t *add_stacknode_beg(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->prev = NULL;/*previous node is alaways NULL*/
	new->next = (*head);/*link new node to head*/
	if ((*head) != NULL)
	{
		(*head)->prev = new;
	}

	(*head) = new;
	return (new);
}

/**
 * delete_stacknode_at_index - delete node a specific spot
 * @head: pointer to first node on list
 * @index: position to delete
 * Return: 1 if successful, -1 if failure
 */

int delete_stacknode_at_index(stack_t **head, unsigned int index)
{
	stack_t *tmp;
	stack_t *tmp2;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	tmp = *head;

	if (index == 0)
	{
		*head = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = NULL;
		free(tmp);
		return (1);
	}
	i = 0;
	while (i < (index - 1))
	{
		if (tmp == NULL)
			return (-1);
		tmp = tmp->next;
		i++;
	}
	tmp2 = (tmp->next)->next;
	if (tmp->next->next != NULL)
		tmp->next->next->prev = tmp;
	free(tmp->next);
	tmp->next = tmp2;

	return (1);
}
~
