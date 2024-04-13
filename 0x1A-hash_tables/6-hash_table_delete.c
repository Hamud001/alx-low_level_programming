#include "hash_tables.h"

/**
 * hash_table_delete - a function that
 * deletes a hash table
 * @ht: is the hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *next, *tmp;
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			next = ht->array[i];
			while (next != NULL)
			{
				tmp = next->next;
				free(next->key);
				free(next->value);
				free(next);
				next = tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
