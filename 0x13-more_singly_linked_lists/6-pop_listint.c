#include "lists.h"

/**
 * pop_listint - function that deletes the head node of a listint_t linked list
 * @head: pointer to initial item in the linked list
 *
 * Return: head node's data (n)
 * or if the linked list is empty return 0
 */
int pop_listint(listint_t **head)
{
	int number = 0;
	listint_t *tempo;

	if (*head == NULL)
		return (0);
	number = (*head)->n;
	tempo = *head;
	*head = (*head)->next;
	free(tempo);

	return (number);
}
