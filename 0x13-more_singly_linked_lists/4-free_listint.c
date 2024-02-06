#include "lists.h"

/**
 * free_listint - function that frees a listint_t list
 * @head: the listint_t which require freeing
 */
void free_listint(listint_t *head)
{
	listint_t *tempo;
	while (head)
	{
		tempo = head->next;
		free(head);
		head = tempo;
	}
}
