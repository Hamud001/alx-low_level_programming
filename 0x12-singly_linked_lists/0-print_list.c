#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint - function with one argument
 * @h: pointer to struct
 *
 * Description: prints all the elements of a list
 * Return: number of nodes
 */
size_t print_listint(const list_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		if (h->str ==NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);

		nodes++;
		h = h->next;
	}

	return (nodes);

}
