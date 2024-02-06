#include "lists.h"
#include <stdio.h>
/**
 * delete_nodeint_at_index - function that deletes the node
 * at index index of a linked list
 * @head: pointer of first node in a linked list
 * @index: is the index of the node that should be deleted
 * index starts at 0
 *
 * Return: 1 if succeeded or -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *variant, *forward;
	unsigned int count = 0;

	variant = *head;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = variant->next;
		free(variant);
		return (1);
	}
	if (index == 1)
	{
		variant = (*head)->next;
		(*head)->next = variant->next;
		free(variant);
		return (1);
	}
	while (count < index - 1)
	{
		if (variant->next == NULL)
			return (-1);
		count++;
		variant = variant->next;
		forward = variant->next;
	}
	variant->next = forward->next;
	free(forward);

	return (1);
}
