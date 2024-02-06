#include "lists.h"

/**
 * add_nodeint_end - function that adds new node at the end of a listint_t list
 * @head:  pointer to head of first item on the  list
 * @n: data to be inserted
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *temp, *newnode;

	temp = *head;
	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	if (*head == NULL)
	{
		*head = newnode;
		return (*head);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newnode;
	return (newnode);
}
