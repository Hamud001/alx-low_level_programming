#include "lists.h"

/**
 * reverse_listint - a function that reverses a listint_t linked list.
 * @head: pointer  of linked list
 *
 * Return:a  pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *past, *connector;

	if (head == NULL || *head == NULL)
		return (NULL);

	if ((*head)->next == NULL)
		return (*head);
	past = *head;
	connector = past->next;
	*head = connector->next;

	past->next = NULL;

	while ((*head)->next != NULL)
	{
		connector->next = past;
		past = connector;
		connector = (*head);
		*head = (*head)->next;
	}

	(*head)->next = connector;
	connector->next = past;
	return (*head);
}
