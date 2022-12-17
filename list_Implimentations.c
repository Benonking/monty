#include "monty.h"

/**
 * add_dnodeint_end - add node at end of doubly linked list
 * @head: point to head of list
 * @n: data/ node to be added
 * Return: new element or NULL on fail
 */

stack_t *add_dnodeint_end(dlistint_t **head, const int n)
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
 * free_dlistint - free doubly linked list
 * @head: point to head of list
 * Return: 0 on sucess
 */

void free_dlistint(stack_t *head)
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
 * add_dnodeint - add new node at the begining of doubly linked list
 * @head: point to head of list
 * @n:data to be added
 * Return: address of new added element or NULL on fail
 */

stack_t *add_dnodeint(dlistint_t **head, const int n)
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
~
