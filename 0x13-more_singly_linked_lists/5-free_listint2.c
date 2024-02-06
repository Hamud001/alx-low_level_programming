#include "lists.h"

/**
 * free_listint2 - writing a function that frees a listint_t list
 * @head: pointer to free listint_t
 */
void free_listint2(listint_t **head)
{
	listint_t *tempo;

	if (head == NULL)
	{
		return;
	}

	while (*head)
	{
		tempo = (*head)->next;
		free(*head);
		*head = tempo;
	}
	*head = NULL;
}
