#include "lists.h"

/**
 * add_nodeint - function that adds  new node at the beginning of a linked list
 * @head:  pointer to the  linked list
 * @n: inserted data of new node
 *
 * Return: pointer of the node  or NULL if fail
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newnode;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = *head;
	*head = newnode;
	return (newnode);
}
