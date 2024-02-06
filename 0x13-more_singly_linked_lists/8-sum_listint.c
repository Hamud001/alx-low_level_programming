#include "lists.h"

/**
 * sum_listint - function that returns the sum of all the data
 * of  linked list
 * @head: pointer to first elememt of the linked list
 *
 * Return: if the list is empty, return 0
 */
int sum_listint(listint_t *head)
{
	unsigned int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
