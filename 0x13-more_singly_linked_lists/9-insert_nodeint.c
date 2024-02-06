#include "lists.h"

/**
 * insert_nodeint_at_index - a function that inserts a new node
 * @head: pointer to the first element
 * @idx: index of list  list where the new node should be added
 * index starts at 0
 * @n: value integer
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *tempo, *variant;
	unsigned int count = 0;

	if (head == NULL)
		return (NULL);

	tempo = malloc(sizeof(listint_t));
	if (tempo == NULL)
		return (NULL);
	tempo->n = n;
	variant = *head;

	if (idx == 0)
	{
		tempo->next = *head;
		*head = tempo;
		return (*head);
	}

	while (variant != NULL)
	{
		if (count == idx - 1)
		{
			tempo->next = variant->next;
			variant->next = tempo;
		}
		count++;
		variant = variant->next;
	}
	if (idx > count)
		return (NULL);
	return (tempo);

}
