#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the nth node of a linked list
 * where index is the index of the node, starting at 0
 * @head: pointer to first node of linked list
 * @index: nth node
 * Return: if the node does not exist, return NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int num = 0;

	while (head != NULL)
	{
		if (num == index)
			return (head);
		head = head->next;
		num++;
	}
	return (NULL);
}
